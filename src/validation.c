/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:32 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/12 16:14:30 by gde-la-r         ###   ########.fr       */
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

static int	valid_chars(t_game *game, int x, int y)
{
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectables_c++;
			else if (game->map[y][x] == 'P')
			{
				game->players_c++;
				if (game->players_c > 1)
					return (0);
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_c++;
				if (game->exit_c > 1)
					return (0);
				game->exit_pos.x = x;
				game->exit_pos.y = y;
			}
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	set_collectables_pos(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->collectable_pos = malloc(sizeof(t_position) * game->collectables_c);
	y = 0;
	i = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				game->collectable_pos[i].x = x;
				game->collectable_pos[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	validations(t_game *game)
{
	if (!valid_lines(game))
		return (ft_free(game, NULL), ft_putstr_fd(MAP_SIZE, 2), 0);
	else if (!valid_walls(game))
		return (ft_free(game, NULL), ft_putstr_fd(MAP_WALLS, 2), 0);
	else if (!valid_chars(game, 0, 0))
		return (ft_free(game, NULL), ft_putstr_fd(INVALID_CHAR, 2), 0);
	set_collectables_pos(game);
	// remember to free this!!!
	return (1);
}
