/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:15 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/12 16:47:39 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_player_pos(t_game *game, int x, int y)
{
	game->players_c++;
	if (game->players_c > 1)
	{
		game->players_c = 0;
		return (0);
	}
	game->player_pos.x = x;
	game->player_pos.y = y;
	return (1);
}

int	set_exit_pos(t_game *game, int x, int y)
{
	game->exit_c++;
	if (game->exit_c > 1)
	{
		game->exit_c = 0;
		return (0);
	}
	game->exit_pos.x = x;
	game->exit_pos.y = y;
	return (1);
}
