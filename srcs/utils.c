/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:20:20 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/06 18:28:07 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
