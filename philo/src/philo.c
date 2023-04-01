/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:41:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/01 02:11:55 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		if (!parser(av) || !philo_args(&info, ac, av))
			return (0);
		init_mutex(&info);
		create_philos(&info);
		destroy_mutex(&info);
	}
}
