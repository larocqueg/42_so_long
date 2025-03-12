/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:06:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:33 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_load_images(t_game *game)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	(*game).img.player = mlx_xpm_file_to_image((*game).mlx, PLAYER, &x, &y);
	(*game).img.collectable = mlx_xpm_file_to_image((*game).mlx, COIN, &x, &y);
	(*game).img.wall = mlx_xpm_file_to_image((*game).mlx, WALL, &x, &y);
	(*game).img.floor = mlx_xpm_file_to_image((*game).mlx, FLOOR, &x, &y);
	(*game).img.door_open = mlx_xpm_file_to_image((*game).mlx, DOORO, &x, &y);
	(*game).img.door_close = mlx_xpm_file_to_image((*game).mlx, DOORC, &x, &y);
	if (!(*game).img.player || !(*game).img.collectable || !(*game).img.wall
		|| !(*game).img.floor || !(*game).img.door_open
		|| !(*game).img.door_close)
		return (0);
	return (1);
}

void	ft_init_window(t_game *game)
{
	int	x;
	int	y;

	game->start = true;
	x = game->map_width * 32;
	y = game->map_height * 32;
	game->win = mlx_new_window(game->mlx, x, y, NAME);
	mlx_loop(game->mlx);
}
