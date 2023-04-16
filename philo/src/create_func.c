/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/16 07:19:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	routine_loop(t_philo *vars)
{
	int	g_d;

	g_d = 0;
	while (!g_d)
	{
		pthread_mutex_lock(&vars->info->mutex);
		g_d = vars->info->g_death;
		pthread_mutex_unlock(&vars->info->mutex);
		if (vars->num_of_eat == vars->info->num_to_eat)
			return ;
		if (vars->info->num_philo == 1)
		{
			pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
			put_logs(vars, vars->id, "has taken a fork", 1);
			pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
			return ;
		}
		else
		{
			is_eating(vars, vars->id);
			is_sleeping(vars, vars->id);
			is_thinking(vars, vars->id);
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*vars;

	vars = arg;
	if (vars->id % 2 == 0)
		usleep(100);
	routine_loop(vars);
	return (NULL);
}

int	max_meals(t_info *vars)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < vars->num_philo)
	{
		if (vars->th[i].num_of_eat == vars->num_to_eat)
			count++;
		if (count == vars->num_philo)
			return (0);
		i++;
	}
	return (1);
}

void	death_loop(t_philo *vars, time_t less_ttd, int def)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&vars->info->mutex);
		less_ttd = get_time() - vars[i].last_eat;
		def = max_meals(vars->info);
		pthread_mutex_unlock(&vars->info->mutex);
		if (less_ttd > vars->info->ttd)
		{
			pthread_mutex_lock(&vars->info->mutex);
			vars->info->g_death = 1;
			pthread_mutex_unlock(&vars->info->mutex);
			pthread_mutex_lock(&vars->info->print);
			put_logs(vars, i, "is died", 0);
			return ;
		}
		if (def == 0)
			return ;
		i++;
		if (i == vars->info->num_philo)
			i = 0;
		usleep(100);
	}
}

void	check_death(t_philo *vars)
{
	time_t			less_ttd;
	int				def;

	def = 0;
	less_ttd = 0;
	death_loop(vars, less_ttd, def);
}
