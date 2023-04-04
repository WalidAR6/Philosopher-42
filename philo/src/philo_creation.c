/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/04 02:34:48 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philos(t_info *vars)
{
	int i;

	i = 0;
	while (i < vars->num_philo)
	{
		vars->th[i].id = i;
		vars->th[i].right_fork = i;
		vars->th[i].left_fork = (i % vars->num_philo) + 1;
		vars->th[i].num_of_eat = 0;
		vars->th[i].info = vars;
		i++;
	}
}

void	start_action(t_info *vars)
{
	int i;

    i = 0;
    while (i < vars->num_philo)
    {
        pthread_create(&vars->th[i].th, NULL, &routine, &vars->th[i]);
        i++;
    }
	usleep(100);
    i = 0;
    while (i < vars->num_philo)
    {
        pthread_detach(vars->th[i].th);
        i++;
	}
}

void	create_philos(t_info *info)
{
	int i;

	i = 0;
	info->th = malloc(info->num_philo * sizeof(t_philo));
	if (!info->th)
		return ;
	init_philos(info);
	start_action(info);
	while (1)
	{
		if (is_dead(info))
			break;
		i++;
	}
}