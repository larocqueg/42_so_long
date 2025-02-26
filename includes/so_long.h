/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:05 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:06 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define NO_FILE	"Error: no such file or directory: "
# define MAP_TYPE	"Error: invlid map format, ensure the file is .ber\n"
# define MAP_SIZE	"Error: invalid map size!\n"
# define MAP_WALLS	"Error: The map is not surrounded by walls!\n"
# define PATH_ERROR "Error: No avaiable path!\n"
# define AV_ERROR	"ERROR\nusage: $> ./so_long map.ber\n"

typedef struct s_map
{
	size_t	width;
	size_t	height;
	size_t	to_colect;
	void	*wall;
	void	*back;
	void	*player;
	void	*coin;
}	t_game;

//utils.c
int	ft_open(char *map);

// validation.c
int	ft_validation(char *map);
int	valid_format(char *map);
int	valid_size(char *map);
int	valid_walls(char *map);
int	valid_path(char *map);

#endif
