/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:25:05 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/06 18:27:11 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(char **map)
{
	int		height;
	char	**map_cpy;
	int		i;

	height = get_map_height(map);
	i = 0;
	map_cpy = malloc((height + 1) * sizeof(char *));
	if (!map_cpy)
		put_erorr("ERROR: Memory allocation failed", map);
	while (i < height)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (--i >= 0)
				free(map_cpy[i]);
			free(map_cpy);
			put_erorr("ERROR: Memory allocation failed", map);
		}
		i++;
	}
	map_cpy[height] = NULL;
	return (map_cpy);
}

static void	get_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
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

static int	flood_fill_map(char **map, int x, int y, t_map_data *map_d)
{
	int	m_width;
	int	m_height;

	m_width = ft_strlen(map[0]);
	m_height = get_map_height(map);
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)
		return (0);
	if (map[y][x] == WALL || map[y][x] == 'v')
		return (0);
	if (map[y][x] == COLLECTIBLE)
		map_d->coins_found++;
	if (map[y][x] == EXIT)
		map_d->exit_found = 1;
	map[y][x] = 'v';
	flood_fill_map(map, x + 1, y, map_d);
	flood_fill_map(map, x - 1, y, map_d);
	flood_fill_map(map, x, y + 1, map_d);
	flood_fill_map(map, x, y - 1, map_d);
	return (map_d->coins_found == map_d->total_coins && map_d->exit_found);
}

int	check_map_solvable(char **map, t_map_data *map_d)
{
	char	**map_copy;
	int		result;

	map_d->total_coins = map_d->coins_found;
	map_d->coins_found = 0;
	map_d->exit_found = 0;
	get_player_position(map, &map_d->t_x, &map_d->t_y);
	map_copy = copy_map(map);
	if (!map_copy)
		put_erorr("ERROR: Memory allocation failed", map);
	result = flood_fill_map(map_copy, map_d->t_x, map_d->t_y, map_d);
	free_map(map_copy);
	return (result);
}
