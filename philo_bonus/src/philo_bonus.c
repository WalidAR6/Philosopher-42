/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:23:51 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/10 23:00:26 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	child_p(t_philo *vars)
{
	if (vars->id % 2 != 0)
		my_usleep(10);
	while (1)
	{
		sem_wait(vars->info->forks);
		put_logs(vars->info->philos, vars->id, "has taken a fork");
		sem_wait(vars->info->forks);
		put_logs(vars->info->philos, vars->id, "has taken a fork");
		put_logs(vars->info->philos, vars->id, "is eating");
		my_usleep(vars->info->tte);
		sem_post(vars->info->forks);
		sem_post(vars->info->forks);
	}
}

void	start_action(t_info *vars)
{
	int i;

	i = 0;
	while (i < vars->num_philo)
	{
		if ((vars->philos[i].ph = fork()) == -1)
			exit(1);
		if (vars->philos[i].ph == 0)
			child_p(&vars->philos[i]);
		i++;
	}
	parent_p();
}

void	init(t_info *vars)
{
	int	i;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

	i = 0;
	vars->forks = sem_open("/sema", O_CREAT | O_EXCL, 0644, vars->num_philo);
	vars->philos = malloc(vars->num_philo * sizeof(t_philo));
	if (!vars->philos)
		return ;
	while(i < vars->num_philo)
	{
		vars->philos[i].id = i;
		vars->philos[i].info = vars;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info	vars;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!parser(av) || !philo_args(&vars, ac, av))
		return (1);
	init(&vars);
	start_action(&vars);
	sem_close(vars.forks);
	sem_unlink("/sema");
	return (0);
}
