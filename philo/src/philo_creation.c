/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/01 14:03:44 by waraissi         ###   ########.fr       */
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
    i = 0;
    while (i < vars->num_philo)
    {
        pthread_join(vars->th[i].th, NULL);
        i++;
	}
}

void	create_philos(t_info *info)
{
	info->th = malloc(info->num_philo * sizeof(t_philo));
	if (!info->th)
		return ;
	init_philos(info);
	start_action(info);
}