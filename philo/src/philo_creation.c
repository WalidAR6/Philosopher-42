/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/05 16:05:57 by waraissi         ###   ########.fr       */
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
	long long i;

	i = 0;
	vars = arg;
	while (1)
	{
		if (get_time(vars->info) - vars[i % vars->info->num_philo].last_eat > vars->info->ttd)
		{
			if(get_time(vars->info) - vars[i % vars->info->num_philo].last_eat > vars->info->ttd)
			{
				put_logs(vars, i % vars->info->num_philo, "died");
				pthread_mutex_lock(&vars->info->death);
				vars[i % vars->info->num_philo].is_dead = 1;
				vars->info->g_death = 1;
				break ;
			}
		}	
		i++;
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
	pthread_create(&vars->death_checker, NULL, &check_death, vars->th);
    i = 0;
    while (i < vars->num_philo)
    {
        pthread_join(vars->th[i].th, NULL);
        i++;
	}
	pthread_join(vars->death_checker, NULL);
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
