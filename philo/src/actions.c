/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:18:20 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/03 16:02:16 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	my_usleep()
{

}

void	is_eating(t_philo *vars, int i)
{
	pthread_mutex_lock(&vars->info->fork[vars->right_fork]);
	put_logs(vars, printf, vars->id, "has take the right fork");
	pthread_mutex_lock(&vars->info->fork[vars->left_fork]);
	put_logs(vars, printf, vars->id, "has take the left fork");
	put_logs(vars, printf, i, "is eating");
	usleep(vars->info->tte * 1000);
	pthread_mutex_unlock(&vars->info->fork[vars->right_fork]);
	pthread_mutex_unlock(&vars->info->fork[vars->left_fork]);
	vars->num_of_eat++;
}

void	is_thinking(t_philo *vars, int i)
{
	put_logs(vars, printf, i, "is thinking");
}

void	is_sleeping(t_philo *vars, int i)
{
	put_logs(vars, printf, i, "is sleeping");
	usleep(vars->info->tts * 1000);
}

int	is_dead(t_info	*vars)
{
	return (0);
}
