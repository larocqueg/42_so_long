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

int	ft_open(char *map)
{
	int		fd;

	if (!valid_format(map))
		return (ft_putstr_fd(MAP_TYPE, 2), 0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(NO_FILE, 2),
			ft_putstr_fd(map, 2), ft_putstr_fd("\n", 2), 0);
	return (1);
}
