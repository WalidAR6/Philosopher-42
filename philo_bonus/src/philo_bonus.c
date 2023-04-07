/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:34:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/07 08:39:52 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!b_parser(av))
			return (1);
	}
	else
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
