/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:18:20 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/04 02:34:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_eating(t_philo *vars, int i)
{
	pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
	put_logs(vars, vars->id, "has take the right fork");
	pthread_mutex_lock(&vars->info->fork[vars->left_fork]);
	put_logs(vars, vars->id, "has take the left fork");
	put_logs(vars, i, "is eating");
	usleep(vars->info->tte * 1000);
	pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
	pthread_mutex_unlock(&vars->info->fork[vars->left_fork]);
	vars->num_of_eat++;
}

void	is_thinking(t_philo *vars, int i)
{
	put_logs(vars, i, "is thinking");
}

void	is_sleeping(t_philo *vars, int i)
{
	put_logs(vars, i, "is sleeping");
	usleep(vars->info->tts * 1000);
}

void	*check_death(void *arg)
{
	t_info *vars;
	int i;

	i = 0;
	vars = arg;
	while (i < vars->num_philo)
	{
		
	}
	return (NULL);
}

int	is_dead(t_info	*vars)
{
	pthread_create(&vars->death_checker, NULL, &check_death, vars->th);
	return (0);
}
