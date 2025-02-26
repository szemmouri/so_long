/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:30:22 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/24 14:00:49 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

// move diriction
# define MOVE_UP 0
# define MOVE_RIGHT 1
# define MOVE_DOWN 2
# define MOVE_LEFT 3

// map_textures
# define WALL 49        // ASCII value for '1'
# define EMPTY 48       // ASCII value for '0'
# define COLLECTIBLE 67 // ASCII value for 'C'
# define EXIT 69        // ASCII value for 'E'
# define PLAYER 80      // ASCII value for 'P'

//  Key Codes
# define KEY_UP 126
# define KEY_W 13
# define KEY_RIGHT 124
# define KEY_D 2
# define KEY_DOWN 125
# define KEY_S 1
# define KEY_LEFT 123
# define KEY_A 0
# define KEY_ESC 53

typedef struct s_map
{
	int		player;
	int		coins_found;
	int		total_coins;
	int		exit_found;
	int		t_x;
	int		t_y;
}			t_map_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_exit;
	void	*img_player_r;
	void	*img_player_l;
	int		win_w;
	int		win_h;
	char	**map;
	int		x_p;
	int		y_p;
	int		movement;
	int		collect;
}			t_game;

// parsing
char		**get_map(char *filename);
void		check_map(char **map);
void		check_elements(char **map, t_map_data *map_d);
void		is_map_rectangular(char **map);
void		is_map_composed(char **map);
int			check_line(char *line);
int			check_map_solvable(char **map, t_map_data *map_d);
void		check_path(char *filename);

// clean up
void		ft_exit(char *message, t_game *game);
void		put_erorr(char *message, char **map);
int			close_window(t_game *game);
void		free_map(char **map);
void		cleanup(t_game *game);

// moves
void		move_player(t_game *game, int direction);

// more utils
void		get_door_position(char **map, int *x, int *y);
int			get_map_height(char **map);
int			check_line(char *line);
void		load_images(t_game *game, int *img_w, int *img_h);

#endif
