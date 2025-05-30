/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:30:59 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/26 11:51:54 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, MOVE_RIGHT);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, MOVE_LEFT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, MOVE_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, MOVE_DOWN);
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

static void	init_vars(t_game *game)
{
	int	img_w;
	int	img_h;

	game->collect = 0;
	game->movement = 0;
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = get_map_height(game->map);
	load_images(game, &img_w, &img_h);
}

static void	put_image_to_map(char c, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
	if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
	else if (c == COLLECTIBLE)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x, y);
		game->collect++;
	}
	else if (c == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x, y);
	else if (c == PLAYER)
	{
		game->y_p = y;
		game->x_p = x;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_r, x, y);
	}
}

static void	render_map(t_game *game)
{
	int	pixel_y;
	int	map_y;
	int	pixel_x;
	int	map_x;

	pixel_y = 0;
	map_y = 0;
	while (map_y < game->win_h)
	{
		pixel_x = 0;
		map_x = 0;
		while (map_x < game->win_w)
		{
			put_image_to_map(game->map[map_y][map_x], pixel_x, pixel_y, game);
			map_x++;
			pixel_x += 50;
		}
		map_y++;
		pixel_y += 50;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./so_long <map.ber>", 2);
		return (1);
	}
	check_path(argv[1]);
	game.map = get_map(argv[1]);
	if (game.map)
	{
		check_map(game.map);
		game.mlx = mlx_init();
		init_vars(&game);
		game.win = mlx_new_window(game.mlx, game.win_w * 50, game.win_h * 50,
				"So Long");
		render_map(&game);
		mlx_hook(game.win, 2, 0, key_hook, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
	}
}
