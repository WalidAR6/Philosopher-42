/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:47:43 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/17 03:02:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*func(void *arg)
{
	t_philo	*vars;
	time_t	last_eat;
	time_t	saved;

	vars = arg;
	while (1)
	{
		sem_wait(vars->info->print);
		saved = vars->last_eat;
		sem_post(vars->info->print);
		last_eat = get_time() - saved;
		if (last_eat > vars->info->ttd)
		{
			put_logs(vars->info->philos, vars->id, "is died", 0);
			free(vars->info->philos);
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}

void	routine(t_philo *vars)
{
	if (vars->id % 2)
		usleep(50);
	while (1)
	{
		if (vars->num_of_eat == vars->info->num_to_eat)
		{
			free(vars->info->philos);
			exit(FINISH_MEAL);
		}
		is_eating(vars);
		is_sleeping(vars);
		is_thinking(vars);
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
	int	i;
	int	status;

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
