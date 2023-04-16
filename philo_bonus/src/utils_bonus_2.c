/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:54:16 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/16 02:03:10 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	kill_p(t_info *vars)
{
	int i;

	i = 0;
	while (i < vars->num_philo)
	{
		kill(vars->philos[i].ph, SIGKILL);
		i++;
	}
	free(vars->philos);
	exit(0);
}

void	init(t_info *vars)
{
	int	i;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

	i = 0;
	vars->forks = sem_open("/sema", O_CREAT , 0644, vars->num_philo);
	vars->print = sem_open("/print", O_CREAT , 0644, 1);
	vars->philos = malloc(vars->num_philo * sizeof(t_philo));
	if (!vars->philos)
		return ;
	while(i < vars->num_philo)
	{
		vars->philos[i].id = i;
		vars->philos[i].last_eat = get_time();
		vars->philos[i].num_of_eat = 0;
		vars->philos[i].is_died = 0;
		vars->philos[i].info = vars;
		i++;
	}
}

void	unlink_semaphores(void)
{
	sem_unlink("/sema");
	sem_unlink("/print");
}

void	close_semaphores(t_info *vars)
{
	sem_close(vars->forks);
	sem_close(vars->print);
	unlink_semaphores();
}
