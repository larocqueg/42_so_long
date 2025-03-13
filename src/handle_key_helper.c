/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:42:10 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/13 16:50:36 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect_check(t_game *game)
{
	if (game->collectables_c == 0)
	{
		game->map[game->exit_pos.y][game->exit_pos.x] = 'O';
		mlx_put_image_to_window(game->mlx, game->win, game->img.door_open,
			game->exit_pos.x * 32, game->exit_pos.y * 32);
	}
	return ;
}

void	redraw_map(t_game *game, int new_x, int new_y, char next_tile)
{
	if (next_tile != '1' && next_tile != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		if (new_x != game->player_pos.x || new_y != game->player_pos.y)
		{
			game->player_pos.x = new_x;
			game->player_pos.y = new_y;
			game->map[new_y][new_x] = 'P';
			ft_printf("Moves: %d\n", ++game->moves_c);
			ft_draw_map(game, 0, 0);
		}
	}
}
