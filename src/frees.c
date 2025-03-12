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
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, (*game).img.player);
		mlx_destroy_image(game->mlx, (*game).img.collectable);
		mlx_destroy_image(game->mlx, (*game).img.wall);
		mlx_destroy_image(game->mlx, (*game).img.floor);
		mlx_destroy_image(game->mlx, (*game).img.door_open);
		mlx_destroy_image(game->mlx, (*game).img.door_close);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}

void	ft_free_collect_pos(t_game *game)
{
	free(game->collectable_pos);
}
