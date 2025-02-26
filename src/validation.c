/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:32 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 14:21:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_format(char *map)
{
	int	format_len;

	format_len = ft_strlen(map) - 4;
	if (ft_strncmp(map + format_len, ".ber", 4) != 0)
		return (0);
	return (1);
}
/*
int	valid_size(char *map)
{
}

int	valid_walls(char *map)
{
}

int	valid_path(char *map)
{
}

int	ft_validation(char *map)
{
	if (!valid_size(map))
		return (ft_putstr_fd(MAP_SIZE, 2), 0);
	else if (!valid_walls(map))
		return (ft_putstr_fd(MAP_WALLS, 2), 0);
	else if (!valid_path(map))
		return (ft_putstr_fd(PATH_ERROR, 2), 0);
	return (1);
}*/
