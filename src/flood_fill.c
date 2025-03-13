/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:28:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/13 22:34:19 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_dup(t_game *game)
{
	int	y;

	y = 0;
	game->map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_copy)
		return ;
	while (y < game->map_height)
	{
		game->map_copy[y] = ft_strdup(game->map[y]);
		if (!game->map_copy[y])
		{
			while (--y >= 0)
				free(game->map_copy[y]);
			free(game->map_copy);
			return ;
		}
		y++;
	}
	game->map_copy[y] = NULL;
}

static bool	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height
		|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'F')
		return (game->exit_found);
	if (game->map_copy[y][x] == 'C')
		game->reachable_c++;
	if (game->map_copy[y][x] == 'E')
	{
		game->reachable_e++;
		game->exit_found = true;
	}
	game->map_copy[y][x] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	return (game->exit_found);
}

bool	flood_fill_caller(t_game *game)
{
	int	i;

	map_dup(game);
	if (!game->map_copy)
		return (false);
	game->reachable_c = 0;
	game->reachable_e = 0;
	flood_fill(game, game->player_pos.x, game->player_pos.y);
	i = 0;
	while (i < game->map_height)
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
	if (game->reachable_c == game->collectables_c && game->reachable_e > 0)
		return (true);
	ft_putstr_fd("Error: Unreachable collectables or exit!\n", 2);
	return (false);
}
