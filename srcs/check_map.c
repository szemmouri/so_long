/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:54 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/12 12:25:24 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_err_message(t_map_data map_d)
{
	if (map_d.coins_found == 0)
		return ("ERROR: At least one collectible must be present in the map.");
	if (map_d.exit_found == 0)
		return ("ERROR: At least one exit must be present in the map.");
	if (map_d.exit_found > 1)
		return ("ERROR: There must be only one exit in the map!");
	if (map_d.player == 0)
		return ("ERROR: At least one player must be present in the map.");
	if (map_d.player > 1)
		return ("ERROR: There must be only one player in the map!");
	if (map_d.enemy > 1)
		return ("ERROR: There must be only one Enemy in the map!");
	return (NULL);
}

void	check_elements(char **map, t_map_data *map_d)
{
	while (map[map_d->t_y])
	{
		map_d->t_x = 0;
		while (map[map_d->t_y][map_d->t_x])
		{
			if (map[map_d->t_y][map_d->t_x] == PLAYER)
				map_d->player++;
			else if (map[map_d->t_y][map_d->t_x] == COLLECTIBLE)
				map_d->coins_found++;
			else if (map[map_d->t_y][map_d->t_x] == EXIT)
				map_d->exit_found++;
			else if (map[map_d->t_y][map_d->t_x] == ENEMY)
				map_d->enemy++;
			else if (map[map_d->t_y][map_d->t_x] != WALL
				&& map[map_d->t_y][map_d->t_x] != EMPTY)
				put_erorr("ERROR: Unknown element", map);
			map_d->t_x++;
		}
		map_d->t_y++;
	}
	if (map_d->coins_found == 0 || map_d->player == 0 || map_d->exit_found == 0
		|| map_d->exit_found > 1 || map_d->player > 1 || map_d->enemy > 1)
		put_erorr(ft_err_message(*map_d), map);
}

void	check_is_rectangular(char **map)
{
	int		y;
	size_t	row_length;

	y = 0;
	if (!map || !map[0])
		put_erorr("ERROR: Invalid map!", map);
	row_length = ft_strlen(map[y]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != row_length)
			put_erorr("ERROR: Map is not rectangular", map);
		y++;
	}
}

void	is_map_composed(char **map)
{
	int	height;

	height = get_map_height(map) - 1;
	if (check_line(map[0]))
		put_erorr("ERROR: Map is not composed", map);
	if (check_line(map[height]))
		put_erorr("ERROR: Map is not composed", map);
	while (height)
	{
		if (map[height][0] != WALL || map[height][ft_strlen(map[0])
			- 1] != WALL)
			put_erorr("ERROR: Map is not composed", map);
		height--;
	}
}

void	check_map(char **map)
{
	t_map_data	map_d;

	map_d.coins_found = 0;
	map_d.player = 0;
	map_d.exit_found = 0;
	map_d.enemy = 0;
	map_d.t_y = 0;
	check_is_rectangular(map);
	is_map_composed(map);
	check_elements(map, &map_d);
	if (!check_map_solvable(map, &map_d))
		put_erorr("ERROR: Invalid map can't finish the Game!!", map);
	if (get_map_height(map) > 163 || ft_strlen(map[0]) > 163)
		put_erorr("ERROR: Invalid map So Loong :)", map);
}
