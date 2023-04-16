/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:47:43 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/16 02:01:49 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*func(void *arg)
{
	t_philo *vars;

	vars = arg;
	while (1)
	{
		if (get_time() - vars->last_eat > vars->info->ttd)
		{
			vars->is_died = 1;
			put_logs(vars->info->philos, vars->id, "is died", 0);
			free(vars->info->philos);
			exit(0);
		}
		usleep(50);
	}
	return (NULL);
}

void	routine(t_philo *vars)
{
	if (vars->id % 2)
		usleep(100);
	while (1)
	{
		if (vars->num_of_eat == vars->info->num_to_eat)
		{
			free(vars->info->philos);
			exit(FINISH_MEAL);
		}
		sem_wait(vars->info->forks);
		put_logs(vars->info->philos, vars->id, "has taken a fork", 1);
		sem_wait(vars->info->forks);
		put_logs(vars->info->philos, vars->id, "has taken a fork", 1);
		put_logs(vars->info->philos, vars->id, "is eating", 1);
		vars->last_eat = get_time();
		vars->num_of_eat++;
		my_usleep(vars->info->tte);
		sem_post(vars->info->forks);
		sem_post(vars->info->forks);
		put_logs(vars->info->philos, vars->id, "is sleeping", 1);
		my_usleep(vars->info->tts);
		put_logs(vars->info->philos, vars->id, "is thinking", 1);
	}
}

void	child_p(t_philo *vars)
{
	pthread_create(&vars->helper, NULL, &func, vars);
	pthread_detach(vars->helper);
	routine(vars);
}

void	start_action(t_info *vars)
{
	int i;
	int status;

	i = 0;
	vars->start_time = get_time();
	while (i < vars->num_philo)
	{
		vars->philos[i].ph = fork();
		if (vars->philos[i].ph == 0)
			child_p(&vars->philos[i]);
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (status == 0)
			kill_p(vars);
	}
}
