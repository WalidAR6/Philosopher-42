/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:18:20 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/06 18:11:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_eating(t_philo *vars, int i)
{
	pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
	put_logs(vars, vars->id, "has taken a fork");
	pthread_mutex_lock(&vars->info->fork[vars->left_fork]);
	put_logs(vars, vars->id, "has taken a fork");
	put_logs(vars, i, "is eating");
	my_usleep(vars->info, vars->info->tte);
	vars->last_eat = get_time(vars->info);
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
	my_usleep(vars->info, vars->info->tts);
}
