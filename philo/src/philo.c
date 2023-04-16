/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:41:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/16 05:14:24 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_free(t_info *info)
{
	free(info->fork);
	free(info->th);
}

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
		ft_free(&info);
		return (1);
	}
	my_usleep(300);
	ft_free(&info);
	destroy_mutex(&info);
	return (0);
}
