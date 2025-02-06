/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:18:39 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/06 18:27:46 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_move(t_game *game)
{
	ft_putstr_fd("Move: ", 1);
	ft_putnbr_fd(++game->movement, 1);
	ft_putchar_fd('\n', 1);
	display_moves(game);
}

static void	cllect_coin(t_game *game)
{
	game->collect--;
	game->map[game->y_p / 50][game->x_p / 50] = EMPTY;
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, game->x_p,
		game->y_p);
}

static void	open_door(t_game *game)
{
	int	img_w;
	int	img_h;
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_door_position(game->map, &x, &y);
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 50, y
		* 50);
	mlx_destroy_image(game->mlx, game->img_exit);
	game->img_exit = mlx_png_file_to_image(game->mlx, "textures/door_o.png",
			&img_w, &img_h);
	mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 50, y
		* 50);
}

static void	*get_dir_move(t_game *game, int direction, int *next_x, int *next_y)
{
	*next_x = game->x_p;
	*next_y = game->y_p;
	if (direction == MOVE_UP)
		*next_y -= 50;
	else if (direction == MOVE_RIGHT)
	{
		*next_x += 50;
		return (game->img_player_r);
	}
	else if (direction == MOVE_DOWN)
		*next_y += 50;
	else if (direction == MOVE_LEFT)
	{
		*next_x -= 50;
		return (game->img_player_l);
	}
	return (game->img_player_r);
}

void	move_player(t_game *game, int direction)
{
	int		next_x;
	int		next_y;
	void	*player_img;

	player_img = get_dir_move(game, direction, &next_x, &next_y);
	if (game->map[next_y / 50][next_x / 50] == COLLECTIBLE
		&& game->collect == 1)
		open_door(game);
	if (game->map[next_y / 50][next_x / 50] == WALL || (game->map[next_y
			/ 50][next_x / 50] == EXIT && game->collect > 0))
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, game->x_p,
		game->y_p);
	if (game->map[next_y / 50][next_x / 50] == EXIT && game->collect == 0)
		ft_exit("\033[1;32mCongrats You Win!\033[0m", game);
	game->x_p = next_x;
	game->y_p = next_y;
	ft_put_move(game);
	if (game->map[game->y_p / 50][game->x_p / 50] == COLLECTIBLE)
		cllect_coin(game);
	mlx_put_image_to_window(game->mlx, game->win, player_img, game->x_p,
		game->y_p);
}
