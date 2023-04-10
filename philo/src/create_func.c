/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/10 19:42:18 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	routine_loop(t_philo *vars, int g_d)
{
	while (1 && !g_d)
	{
		pthread_mutex_lock(&vars->info->mutex);
		g_d = vars->info->g_death;
		pthread_mutex_unlock(&vars->info->mutex);
		if (g_d)
			return ;
		if (vars->info->ac == 6 && vars->num_of_eat == vars->info->num_to_eat)
			return ;
		if (vars->info->num_philo == 1)
		{
			pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
			put_logs(vars, vars->id, "has taken a fork");
			pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
			return ;
		}
		else
		{
			if (g_d)
				return ;
			is_eating(vars, vars->id);
			is_sleeping(vars, vars->id);
			is_thinking(vars, vars->id);
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*vars;
	int		g_d;

	g_d = 0;
	vars = arg;
	if (vars->id % 2 == 0)
		my_usleep(10);
	routine_loop(vars, g_d);
	return (NULL);
}

void	death_loop(t_philo *vars, time_t less_ttd, int def)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&vars->info->mutex);
		less_ttd = get_time() - vars[i].last_eat;
		def = vars[i].num_of_eat - vars->info->num_to_eat;
		pthread_mutex_unlock(&vars->info->mutex);
		if (less_ttd > vars->info->ttd)
		{
			pthread_mutex_lock(&vars->info->mutex);
			vars->info->g_death = 1;
			pthread_mutex_unlock(&vars->info->mutex);
			my_usleep(5);
			printf("%ldms\t%d %s\n",
				get_time() - vars->info->start_time, i, "is died");
			return ;
		}
		else if (def == 0)
			return ;
		i++;
		if (i == vars->info->num_philo)
			i = 0;
	}
}

void	*check_death(void *arg)
{
	t_philo			*vars;
	time_t			less_ttd;
	int				def;

	def = 0;
	less_ttd = 0;
	vars = arg;
	death_loop(vars, less_ttd, def);
	return (NULL);
}
