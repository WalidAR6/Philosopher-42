/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:54:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/02 01:33:18 by waraissi         ###   ########.fr       */
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
		usleep (1000);
	while (1)
	{
		is_eating(vars, vars->id);
		is_sleeping(vars, vars->id);
		is_thinking(vars, vars->id);
	}
	return (NULL);
}
