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

# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define LEFT_KEY	65361
# define UP_KEY		65362
# define RIGHT_KEY	65363
# define DOWN_KEY	65364
# define ESC_KEY	65307

/* ************************************************************************** */
/*                            Message Macros                                  */
/* ************************************************************************** */

# define NO_FILE		"Error: no such file or directory: "
# define FORMAT_ERROR	"Error: invlid map format, ensure the file is .ber\n"
# define MAP_SIZE		"Error: invalid map size!\n"
# define MAP_WALLS		"Error: The map is not surrounded by walls!\n"
# define INVALID_CHAR	"Error: There is a invalid character in the map!\n"
# define PATH_ERROR		"Error: No avaiable path!\n"
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
	int			map_height;
	int			map_width;
	int			players_c;
	int			exit_c;
	int			collectables_c;
	bool		exit_access;
	bool		start;
	bool		door_open;
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

//game_start.c
void	game_init(t_game *game);
int		ft_load_map(char *map, t_game *game);

//frees.c
void	ft_free(t_game *game, char *line);
void	ft_free_arr(char **arr);
void	ft_free_collect_pos(t_game *game);

//load_images.c
int		ft_load_images(t_game *game);
void	ft_init_window(t_game *game);

#endif
