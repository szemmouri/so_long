/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:20:20 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/26 11:52:31 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_door_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == EXIT)
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL)
			return (1);
		i++;
	}
	return (0);
}

void	load_images(t_game *game, int *img_w, int *img_h)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			img_w, img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			img_w, img_h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			img_w, img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/door_c.xpm",
			img_w, img_h);
	game->img_player_r = mlx_xpm_file_to_image(game->mlx,
			"textures/player_r.xpm", img_w, img_h);
	game->img_player_l = mlx_xpm_file_to_image(game->mlx,
			"textures/player_l.xpm", img_w, img_h);
	game->e_data.img_enemy_l = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy_l.xpm", img_w, img_h);
	game->e_data.img_enemy_r = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy_r.xpm", img_w, img_h);
	if (!game->img_floor || !game->img_wall || !game->img_collect
		|| !game->img_exit || !game->img_player_r || !game->img_player_l
		|| !game->e_data.img_enemy_l || !game->e_data.img_enemy_r)
	{
		ft_putendl_fd("ERROR: Failed to load images", 2);
		cleanup(game);
		exit(1);
	}
}

void	display_moves(t_game *game)
{
	char *moves;
	char *tmp;

	tmp = ft_itoa(++game->movement);
	moves = ft_strjoin("Move: ", tmp);
	free(tmp);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 50, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, 50 * 2, 0);
	mlx_string_put(game->mlx, game->win, 12, 20, 0x000000, moves);
	free(moves);
}