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
	if (ac != 2)
		return (ft_putstr_fd(AV_ERROR, 2));
	if (!ft_validation(av[1]));
		return (1);
	return (0);
}
