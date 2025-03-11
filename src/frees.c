/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:37 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/10 18:03:34 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_game *game, char *line)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	if (game && game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}
