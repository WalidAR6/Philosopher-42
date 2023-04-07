/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:41:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/07 08:25:40 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		if (!parser(av) || !philo_args(&info, ac, av))
			return (1);
		if (init_mutex(&info) || create_philos(&info))
		{
			free(info.fork);
			free(info.th);
			return (1);
		}
		destroy_mutex(&info);
	}
	else
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
