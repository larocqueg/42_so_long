/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:12 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:14 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		fd = ft_open(av[1]);
		if (!fd)
			return (1);
		ft_printf("Valid format and existing file!, fd = %i\n", fd);
		return (close(fd), 0);
	}
	return (ft_putstr_fd(AV_ERROR, 2), 1);
}
