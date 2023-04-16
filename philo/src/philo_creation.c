/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/16 07:05:14 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philos(t_info *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->num_philo)
	{
		vars->th[i].id = i + 1;
		vars->th[i].right_fork = i;
		vars->th[i].num_of_eat = 0;
		vars->th[i].info = vars;
		vars->th[i].last_eat = get_time();
		vars->th[i].done_eating = 0;
		i++;
	}
	i = 0;
	j = 1;
	while (i < vars->num_philo)
	{
		if (j == vars->num_philo)
			j = 0;
		vars->th[i].left_fork = &vars->th[j].right_fork;
		j++;
		i++;
	}
}

void	start_action(t_info *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_philo)
	{
		pthread_create(&vars->th[i].th, NULL, &routine, &vars->th[i]);
		i++;
	}
	i = 0;
	while (i < vars->num_philo)
	{
		pthread_detach(vars->th[i].th);
		i++;
	}
	check_death(vars->th);
}

int	create_philos(t_info *info)
{
	info->th = malloc(info->num_philo * sizeof(t_philo));
	if (!info->th)
		return (1);
	init_philos(info);
	start_action(info);
	return (0);
}
