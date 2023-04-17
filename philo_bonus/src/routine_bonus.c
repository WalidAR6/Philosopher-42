/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:58:56 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/17 03:02:15 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	is_eating(t_philo *vars)
{
	sem_wait(vars->info->forks);
	put_logs(vars->info->philos, vars->id, "has taken a fork", 1);
	sem_wait(vars->info->forks);
	put_logs(vars->info->philos, vars->id, "has taken a fork", 1);
	put_logs(vars->info->philos, vars->id, "is eating", 1);
	sem_wait(vars->info->print);
	vars->last_eat = get_time();
	sem_post(vars->info->print);
	vars->num_of_eat++;
	my_usleep(vars->info->tte);
	sem_post(vars->info->forks);
	sem_post(vars->info->forks);
}

void	is_sleeping(t_philo *vars)
{
	put_logs(vars->info->philos, vars->id, "is sleeping", 1);
	my_usleep(vars->info->tts);	
}

void	is_thinking(t_philo *vars)
{
	put_logs(vars->info->philos, vars->id, "is thinking", 1);	
}
