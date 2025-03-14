/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:05 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/10 11:22:17 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

/* ************************************************************************** */
/*                            key Macros                                      */
/* ************************************************************************** */

# define W		119
# define A		97
# define S		115
# define D		100
# define LEFT	65361
# define UP		65362
# define RIGHT	65363
# define DOWN	65364
# define ESC	65307

/* ************************************************************************** */
/*                            Message Macros                                  */
/* ************************************************************************** */

# define EMPTY			"Error: empty or invalid file!\n"
# define NO_FILE		"Error: no such file or directory: "
# define FORMAT_ERROR	"Error: invlid map format, ensure the file is .ber\n"
# define MAP_SIZE		"Error: invalid map size!\n"
# define MAP_WALLS		"Error: The map is not surrounded by walls!\n"
# define INVALID_CHAR	"Error: There is a invalid character in the map!\n"
# define PATH_ERROR		"Error: No avaiable path!\n"
# define INV_C			"Error: Invalid amount of players, "
# define INV_C2			"exits or collectables!\n"
# define AV_ERROR		"ERROR\nusage: $> ./so_long map.ber\n"

/* ************************************************************************** */
/*                            Textures Macro                                  */
/* ************************************************************************** */

# define NAME			"so_long"
# define FLOOR			"textures/floor.xpm"
# define WALL			"textures/wall.xpm"
# define COIN			"textures/emerald.xpm"
# define PLAYER			"textures/player.xpm"
# define DOORC			"textures/close_door.xpm"
# define DOORO			"textures/open_door.xpm"

/* ************************************************************************** */
/*                                    Structs                                 */
/* ************************************************************************** */

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*title;
	void	*player;
	void	*collectable;
	void	*wall;
	void	*floor;
	void	*door_open;
	void	*door_close;
}	t_images;

typedef struct s_game
{
	int			fd;
	char		**map;
	char		**map_copy;
	int			map_height;
	int			map_width;
	int			players_c;
	int			exit_c;
	int			collectables_c;
	int			reachable_c;
	int			reachable_e;
	bool		exit_access;
	bool		start;
	bool		door_open;
	bool		exit_found;
	int			moves_c;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	*collectable_pos;
	void		*mlx;
	void		*win;
	t_images	img;
}	t_game;

/* ************************************************************************** */
/*                               Prototypes                                   */
/* ************************************************************************** */

//validation.c
int		validations(t_game *game);

//positions.c
int		set_player_pos(t_game *game, int x, int y);
int		set_exit_pos(t_game *game, int x, int y);

//utils.c
int		ft_open(char *map, t_game *game);
int		new_pos_x(int key, t_game *game, int new_y, int new_x);
int		new_pos_y(int key, t_game *game, int new_y, int new_x);
int		is_open(t_game *game, char next_tile);

//game_start.c
void	game_init(t_game *game);
int		ft_load_map(char *map, t_game *game);

//frees.c
int		close_window(t_game *game);
void	ft_free(t_game *game, char *line, int flag);
void	ft_free_arr(char **arr);
void	ft_free_collect_pos(t_game *game);

//load_images.c
int		ft_load_images(t_game *game);
void	ft_init_window(t_game *game);
void	ft_draw_map(t_game *game, int x, int y);
int		handle_key(int key, t_game *game);

//handle_key_helper.c
void	collect_check(t_game *game);
void	redraw_map(t_game *game, int new_x, int new_y, char next_tile);

//flood_fill.c
bool	flood_fill_caller(t_game *game);

#endif
