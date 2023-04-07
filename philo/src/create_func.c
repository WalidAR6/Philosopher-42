/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/07 06:12:38 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	put_logs(t_philo *vars, int i, char *str)
{
	pthread_mutex_lock(&vars->info->print);
	if (!vars->info->g_death)
		printf("%ldms\t%d %s\n",
			get_time() - vars->info->start_time, i, str);
	pthread_mutex_unlock(&vars->info->print);
}

void	*routine(void *arg)
{
	t_philo	*vars;

	vars = arg;
	if (vars->id % 2 != 0)
		my_usleep(10);
	while (1 && !vars->info->g_death)
	{
		if (vars->info->ac == 6 && vars->num_of_eat == vars->info->num_to_eat)
			return (NULL);
		if (vars->info->num_philo == 1)
		{
			pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
			put_logs(vars, vars->id, "has taken a fork");
			pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
			return (NULL);
		}
		else
		{
			is_eating(vars, vars->id);
			is_sleeping(vars, vars->id);
			is_thinking(vars, vars->id);
		}
	}
	return (NULL);
}

void	*check_death(void *arg)
{
	t_philo			*vars;
	unsigned long	less_ttd;
	int				i;

	i = 0;
	vars = arg;
	while (1)
	{
		less_ttd = get_time() - vars[i].last_eat;
		if (less_ttd > vars->info->ttd)
		{
			put_logs(vars, i, "died");
			vars[i].is_dead = 1;
			vars->info->g_death = 1;
			break ;
		}
		else if (vars[i].num_of_eat == vars->info->ac)
			return (NULL);
		i++;
		if (i == vars->info->num_philo)
			i = 0;
	}
	return (NULL);
}
