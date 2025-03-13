/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:12 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/10 14:10:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game_init(&game);
		ft_load_map(av[1], &game);
		if (!validations(&game))
			return (1);
		game.mlx = mlx_init();
		if (!ft_load_images(&game))
			return (ft_free(&game, NULL), ft_free_collect_pos(&game), 1);
		ft_init_window(&game);
		ft_draw_map(&game, 0, 0);
		mlx_key_hook(game.win, handle_key, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (ft_putstr_fd(AV_ERROR, 2), 1);
}
