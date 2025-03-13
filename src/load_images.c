/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:06:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/03/12 20:08:33 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_load_images(t_game *game)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	(*game).img.player = mlx_xpm_file_to_image((*game).mlx, PLAYER, &x, &y);
	(*game).img.collectable = mlx_xpm_file_to_image((*game).mlx, COIN, &x, &y);
	(*game).img.wall = mlx_xpm_file_to_image((*game).mlx, WALL, &x, &y);
	(*game).img.floor = mlx_xpm_file_to_image((*game).mlx, FLOOR, &x, &y);
	(*game).img.door_open = mlx_xpm_file_to_image((*game).mlx, DOORO, &x, &y);
	(*game).img.door_close = mlx_xpm_file_to_image((*game).mlx, DOORC, &x, &y);
	if (!(*game).img.player || !(*game).img.collectable || !(*game).img.wall
		|| !(*game).img.floor || !(*game).img.door_open
		|| !(*game).img.door_close)
		return (0);
	return (1);
}

void	ft_init_window(t_game *game)
{
	int	x;
	int	y;

	game->start = true;
	x = game->map_width * 32;
	y = game->map_height * 32;
	game->win = mlx_new_window(game->mlx, x, y, NAME);
	mlx_hook(game->win, 17, 0L, close_window, game);
}

void	ft_draw_map(t_game *game, int x, int y)
{
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					(*game).img.wall, x * 32, y * 32);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					(*game).img.floor, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					(*game).img.player, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					(*game).img.collectable, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
			{
				if (game->door_open)
					mlx_put_image_to_window(game->mlx, game->win,
						(*game).img.door_open, x * 32, y * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						(*game).img.door_close, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

int	handle_key(int key, t_game *game)
{
	char	next_tile;
	int		new_x;
	int		new_y;

	new_x = game->player_pos.x;
	new_y = game->player_pos.y;
	if (key == ESC)
	{
		ft_printf("EXITING GAME!\n");
		ft_free(game, NULL);
		exit(0);
	}
	else if ((key == UP || key == W) && game->map[new_y - 1][new_x] != '1')
		new_y--;
	else if ((key == DOWN || key == S) && game->map[new_y + 1][new_x] != '1')
		new_y++;
	else if ((key == LEFT || key == A) && game->map[new_y][new_x - 1] != '1')
		new_x--;
	else if ((key == RIGHT || key == D) && game->map[new_y][new_x + 1] != '1')
		new_x++;
	next_tile = game->map[new_y][new_x];
	if (next_tile == 'C')
		ft_printf("Collectables left: %d\n", --game->collectables_c);
	if (next_tile == 'E' || next_tile == 'O')
	{
		if (game->collectables_c == 0)
		{
			ft_printf("🎉 You won in %d moves! 🎉\n", game->moves_c);
			ft_free(game, NULL);
			exit(0);
		}
		return (ft_printf("Exit is locked! Collect all emeralds first!\n"), 0);
	}
	if (game->collectables_c == 0)
	{
		game->map[game->exit_pos.y][game->exit_pos.x] = 'O';
		mlx_put_image_to_window(game->mlx, game->win, game->img.door_open,
			game->exit_pos.x * 32, game->exit_pos.y * 32);
	}
	if (next_tile != '1' && next_tile != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		game->map[new_y][new_x] = 'P';
		ft_printf("Moves: %d\n", game->moves_c++);
		ft_draw_map(game, 0, 0);
	}
	return (0);
}
