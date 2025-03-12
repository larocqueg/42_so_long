/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:32 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 14:21:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_lines(t_game *game)
{
	int	y;
	int	x;
	int	prev_len;
	int	len;

	y = 0;
	prev_len = -1;
	while (game->map[y])
	{
		x = 0;
		len = 0;
		while (game->map[y][x])
		{
			x++;
			len++;
		}
		if (prev_len != -1 && len != prev_len)
			return (0);
		prev_len = len;
		y++;
	}
	game->map_width = prev_len;
	game->map_height = y;
	return (1);
}

static int	valid_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[0][x] && x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	validations(t_game *game)
{
	if (!valid_lines(game))
		return (ft_free(game, NULL), ft_putstr_fd(MAP_SIZE, 2), 0);
	else if (!valid_walls(game))
		return (ft_free(game, NULL), ft_putstr_fd(MAP_WALLS, 2), 0);
	return (1);
}
