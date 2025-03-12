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

//flood_fill
