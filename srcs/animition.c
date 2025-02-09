/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:59:10 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/09 14:31:18 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_moves(t_game *game)
{
	char	*moves;
	char	*tmp;

	tmp = ft_itoa(game->movement);
	moves = ft_strjoin("Move: ", tmp);
	free(tmp);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 50, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 50 * 2, 0);
	mlx_string_put(game->mlx, game->win, 12, 20, 0x000000, moves);
	free(moves);
}

static int	get_random_number(void)
{
	static int	counter = 0;
	static int	direction = 0;

	counter++;
	if (counter > 5)
	{
		direction = (direction + 1) % 4;
		counter = 0;
	}
	return (direction);
}

static void	*get_dir_move(t_game *game, int direction, int *next_x, int *next_y)
{
	*next_x = game->e_data.x_e;
	*next_y = game->e_data.y_e;
	if (direction == MOVE_UP)
		*next_y -= 50;
	else if (direction == MOVE_RIGHT)
	{
		*next_x += 50;
		return (game->e_data.img_enemy_r);
	}
	else if (direction == MOVE_DOWN)
		*next_y += 50;
	else if (direction == MOVE_LEFT)
	{
		*next_x -= 50;
		return (game->e_data.img_enemy_l);
	}
	return (game->e_data.img_enemy_l);
}

static void	move_enemy(t_game *game, int direction)
{
	int		next_x;
	int		next_y;
	void	*enemy_img;

	enemy_img = get_dir_move(game, direction, &next_x, &next_y);
	if (game->map[next_y / 50][next_x / 50] == EMPTY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->e_data.x_e, game->e_data.y_e);
		game->map[game->e_data.y_e / 50][game->e_data.x_e / 50] = EMPTY;
		game->e_data.x_e = next_x;
		game->e_data.y_e = next_y;
		game->map[game->e_data.y_e / 50][game->e_data.x_e / 50] = ENEMY;
		mlx_put_image_to_window(game->mlx, game->win, enemy_img,
			game->e_data.x_e, game->e_data.y_e);
	}
}

int	animation(t_game *game)
{
	static int	frame = 0;

	if (game->e_data.x_e == game->x_p && game->e_data.y_e == game->y_p)
		ft_exit("\033[1;31mGame Over! \033[0m", game);
	frame++;
	if (frame < 10000)
		return (0);
	frame = 0;
	game->e_data.move_dir = get_random_number();
	if (game->e_data.move_dir == MOVE_UP)
		move_enemy(game, MOVE_UP);
	else if (game->e_data.move_dir == MOVE_RIGHT)
		move_enemy(game, MOVE_RIGHT);
	else if (game->e_data.move_dir == MOVE_DOWN)
		move_enemy(game, MOVE_DOWN);
	else
		move_enemy(game, MOVE_LEFT);
	return (0);
}
