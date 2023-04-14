/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:41:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/14 05:40:20 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!parser(av) || !philo_args(&info, ac, av))
		return (1);
	if (init_mutex(&info) || create_philos(&info))
	{
		free(info.fork);
		free(info.th);
		return (1);
	}
	destroy_mutex(&info);
	return (0);
}
