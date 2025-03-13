/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:02:44 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 16:04:04 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static int	valid_format(char *map)
{
	int	form_len;

	form_len = ft_strlen(map);
	if (form_len >= 4)
		form_len -= 4;
	if (ft_strncmp(map + form_len, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	ft_open(char *map, t_game *game)
{
	game->fd = open(map, O_RDONLY);
	if (game->fd == -1)
		return (close(game->fd), ft_putstr_fd(NO_FILE, 2),
			ft_putstr_fd(map, 2), ft_putstr_fd("\n", 2), 0);
	if (!valid_format(map))
		return (close(game->fd), ft_putstr_fd(FORMAT_ERROR, 2), 0);
	return (game->fd);
}

int	new_pos_x(int key, t_game *game, int new_y, int new_x)
{
	if ((key == LEFT || key == A) && game->map[new_y][new_x - 1] != '1')
		new_x--;
	else if ((key == RIGHT || key == D) && game->map[new_y][new_x + 1] != '1')
		new_x++;
	return (new_x);
}

int	new_pos_y(int key, t_game *game, int new_y, int new_x)
{
	if ((key == UP || key == W) && game->map[new_y - 1][new_x] != '1')
		new_y--;
	else if ((key == DOWN || key == S) && game->map[new_y + 1][new_x] != '1')
		new_y++;
	return (new_y);
}

int	is_open(t_game *game, char next_tile)
{
	if (next_tile == 'E' || next_tile == 'O')
	{
		if (game->collectables_c == 0)
		{
			ft_printf("🎉You won in %d moves!🎉\n", game->moves_c);
			ft_free(game, NULL, 1);
			exit(0);
		}
		return (ft_printf("Exit is locked! Collect all emeralds first!\n"), 0);
	}
	return (1);
}
