/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:11:13 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/09 12:29:35 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(char *message, t_game *game)
{
	ft_putendl_fd(message, 1);
	cleanup(game);
	exit(0);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
}

void	put_erorr(char *message, char **map)
{
	ft_putendl_fd(message, 2);
	free_map(map);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	cleanup(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player_l)
		mlx_destroy_image(game->mlx, game->img_player_l);
	if (game->img_player_r)
		mlx_destroy_image(game->mlx, game->img_player_r);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->e_data.img_enemy_l)
		mlx_destroy_image(game->mlx, game->e_data.img_enemy_r);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	free_map(game->map);
}
