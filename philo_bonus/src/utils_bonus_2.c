/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:54:16 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/17 03:15:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	kill_p(t_info *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_philo)
	{
		kill(vars->philos[i].ph, SIGKILL);
		i++;
	}
	close_semaphores(vars);
	free(vars->philos);
	exit(0);
}

void	init(t_info *vars)
{
	int	i;

	i = 0;
	vars->forks = sem_open("/sema", O_CREAT, 0644, vars->num_philo);
	vars->print = sem_open("/printing", O_CREAT, 0644, 1);
	vars->philos = malloc(vars->num_philo * sizeof(t_philo));
	if (!vars->philos)
	{
		close_semaphores(vars);
		return ;
	}
	while (i < vars->num_philo)
	{
		vars->philos[i].id = i;
		vars->philos[i].last_eat = get_time();
		vars->philos[i].num_of_eat = 0;
		vars->philos[i].info = vars;
		i++;
	}
}

void	unlink_semaphores(void)
{
	sem_unlink("/sema");
	sem_unlink("/printing");
}

void	close_semaphores(t_info *vars)
{
	unlink_semaphores();
	sem_close(vars->forks);
	sem_close(vars->print);
}
