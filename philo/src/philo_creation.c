/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/04 16:31:00 by waraissi         ###   ########.fr       */
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
		vars->th[i].is_dead = 0;
		vars->th[i].info = vars;
		vars->th[i].last_eat = get_time(vars->th->info);
		i++;
	}
}

void	*check_death(void *arg)
{
	t_philo *vars;
	int i;

	i = 0;
	vars = arg;
	while (1)
	{
		pthread_mutex_lock(&vars->info->death);
		if (get_time(vars->info) - vars[i % vars->info->num_philo].last_eat > vars->info->ttd)
		{
			pthread_mutex_lock(&vars->info->print);
			printf("filo die %d\n", i % vars->info->num_philo);
			vars[i % vars->info->num_philo].is_dead = 1;
			pthread_mutex_unlock(&vars->info->print);
			break ;
		}	
		else
			i++;
		pthread_mutex_unlock(&vars->info->death);
	}
	return (NULL);
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
	pthread_create(&vars->death_checker, NULL, &check_death, vars->th);
    i = 0;
    while (i < vars->num_philo)
    {
        pthread_detach(vars->th[i].th);
        i++;
	}
	pthread_detach(vars->death_checker);
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
		if (info->th[i % info->num_philo].is_dead == 1)
			exit(0) ;
		i++;
	}
}