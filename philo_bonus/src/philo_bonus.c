/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:23:51 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/09 07:33:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	init_sem(t_info *vars)
{
	int i;

	i = 0;
	vars->forks = malloc(vars->num_philo * sizeof(sem_t));
	if (!vars->forks)
		return ;
	while (i < vars->forks)
	{
		vars->forks[i] = sem_open("/semaphore", O_CREAT | O_EXCL, vars->num_philo);
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
	init_sem(&vars);
	return (0);
}