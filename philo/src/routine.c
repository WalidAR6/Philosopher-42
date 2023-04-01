/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/01 02:40:36 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    put_logs(t_philo *vars, int (*f)(const char *,...), int i, char *str)
{
    pthread_mutex_lock(&vars->info->print);
    f("%d %s\n", i, str);
    pthread_mutex_unlock(&vars->info->print);
}

void	*routine(void *arg)
{
	t_philo *vars;
	vars = arg;
	if (vars->id % 2 != 0)
		usleep (vars->info->tte*1000);
	while (1)
	{
		pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
		put_logs(vars, printf, vars->id, "has take the right fork");
		pthread_mutex_lock(&vars->info->fork[vars->left_fork]);
		put_logs(vars, printf, vars->id, "has take the left fork");
		is_eating(vars, vars->id);
		pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
		pthread_mutex_unlock(&vars->info->fork[vars->left_fork]);
		is_thinking(vars, vars->id);
	}
	return (NULL);
}
