/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/05 02:30:41 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    put_logs(t_philo *vars, int i, char *str)
{
    pthread_mutex_lock(&vars->info->print);
    printf("%ldms\t%d %s\n",get_time(vars->info) - vars->info->start_time, i, str);
    pthread_mutex_unlock(&vars->info->print);
}

void	*routine(void *arg)
{
	t_philo *vars;

	vars = arg;
	if (vars->id % 2 != 0)
		my_usleep(vars->info, 10);
	while (1)
	{
		if (vars->info->num_philo == 1)
		{
			pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
			put_logs(vars, vars->id, "has take the right fork");
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
