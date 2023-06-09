/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:18:20 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/12 02:47:49 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_eating(t_philo *vars, int i)
{
	pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
	put_logs(vars, i, "has taken a fork", 1);
	pthread_mutex_lock(&vars->info->fork[*vars->left_fork]);
	put_logs(vars, i, "has taken a fork", 1);
	put_logs(vars, i, "is eating", 1);
	pthread_mutex_lock(&vars->info->mutex);
	vars->num_of_eat++;
	vars->last_eat = get_time();
	pthread_mutex_unlock(&vars->info->mutex);
	my_usleep(vars->info->tte);
	pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
	pthread_mutex_unlock(&vars->info->fork[*vars->left_fork]);
}

void	is_thinking(t_philo *vars, int i)
{
	put_logs(vars, i, "is thinking", 1);
}

void	is_sleeping(t_philo *vars, int i)
{
	put_logs(vars, i, "is sleeping", 1);
	my_usleep(vars->info->tts);
}
