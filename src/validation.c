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

static int	valid_size(char *map)
{
	(void)map;
	return (1);
}

static int	valid_walls(char *map)
{
	(void)map;
	return (1);
}

static int	valid_path(char *map)
{
	(void)map;
	return (1);
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
}
