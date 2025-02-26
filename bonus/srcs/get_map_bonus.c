/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:13:04 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/26 11:43:45 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	free_line(char *message, char **line, char **map)
{
	ft_putendl_fd(message, 2);
	if (line)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
	if (!map || !*map)
		exit(1);
	free(*map);
	*map = NULL;
	exit(1);
}

static char	*read_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!line || !*line || *line == '\n')
			free_line("ERROR: Invalid Map!", &line, &map);
		tmp = map;
		if (!map)
			map = ft_strdup(line);
		else
		{
			map = ft_strjoin(tmp, line);
			free(tmp);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

char	**get_map(char *filename)
{
	int		fd;
	char	**map;
	char	*tmp_map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("ERORR: Please Enter a valid Path!", 2);
		exit(1);
	}
	tmp_map = read_map(fd);
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	if (!map)
	{
		ft_putendl_fd("ERROR: Invalid Map!", 2);
		exit(1);
	}
	return (map);
}

void	check_path(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e' || filename[len
		- 3] != 'b' || filename[len - 4] != '.' || filename[len - 5] == '/')
	{
		ft_putendl_fd("ERROR: file is not valid must be <filename.ber>", 2);
		exit(1);
	}
}
