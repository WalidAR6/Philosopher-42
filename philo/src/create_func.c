/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/09 01:31:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	put_logs(t_philo *vars, int i, char *str)
{
	int ok;

	pthread_mutex_lock(&vars->info->mutex);
	ok = vars->info->g_death;
	pthread_mutex_unlock(&vars->info->mutex);
	pthread_mutex_lock(&vars->info->print);
	if (!ok)
		printf("%ldms\t%d %s\n",
			get_time() - vars->info->start_time, i + 1, str);
	pthread_mutex_unlock(&vars->info->print);
}

void	*routine(void *arg)
{
	t_philo	*vars;
	int		g_d;

	g_d = 0;
	vars = arg;
	if (vars->id % 2 != 0)
		my_usleep(10);
	while (!g_d)
	{
		pthread_mutex_lock(&vars->info->mutex);
		g_d = vars->info->g_death;
		pthread_mutex_unlock(&vars->info->mutex);
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
	time_t	less_ttd;
	int				def;
	int				i;

	i = 0;
	vars = arg;
	while (1)
	{
		pthread_mutex_lock(&vars->info->mutex);
		less_ttd = get_time() - vars[i].last_eat;
		def = vars[i].num_of_eat - vars->info->num_to_eat;
		pthread_mutex_unlock(&vars->info->mutex);
		if (less_ttd > vars->info->ttd)
		{
			put_logs(vars, i, "is died");
			pthread_mutex_lock(&vars->info->mutex);
			vars->info->g_death = 1;
			pthread_mutex_unlock(&vars->info->mutex);
			break ;
		}
		else if (def == 0)
			return (NULL);
		i++;
		if (i == vars->info->num_philo)
			i = 0;
	}
	return (NULL);
}
