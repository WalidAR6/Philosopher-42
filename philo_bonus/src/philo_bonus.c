/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:23:51 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/09 18:38:17 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	start_action(t_info *vars)
{
	// int i;

	// i = 0;
	// while (i < vars->num_philo)
	// {
	// 	if ((vars->philos[i].ph = fork()) < 0)
	// 		exit(1);
	// 	if (vars->philos[i].ph == 0)
	// 	{
	// 		if (vars->philos[i].id % 2 != 0)
	// 			usleep(100);
	// 		while (1)
	// 		{
	// 			sem_wait(&vars->forks[vars->philos->right_fork]);
	// 			put_logs(vars->philos, i, "has taken a fork");
	// 			sem_wait(&vars->forks[vars->philos->left_fork]);
	// 			put_logs(vars->philos, i, "has taken a fork");
	// 			put_logs(vars->philos, i, "is eating");
	// 			usleep(vars->tte * 1000);
	// 			sem_post(&vars->forks[vars->philos->right_fork]);
	// 			sem_post(&vars->forks[vars->philos->left_fork]);
	// 			put_logs(vars->philos, i, "is sleeping");
	// 			usleep(vars->tts * 1000);
	// 			put_logs(vars->philos, i, "is thinking");
	// 		}
	// 	}
	// 	i++;
	// }
	
}

void	init_philos(t_info *vars)
{
	int	i;

	i = 0;
	vars->philos = malloc(vars->num_philo * sizeof(t_philo));
	if (!vars->philos)
		return ;
	while(i < vars->num_philo)
	{
		vars->philos[i].id = i;
		vars->philos[i].right_fork = i;
		vars->philos[i].left_fork = (i % vars->num_philo) + 1;
		vars->philos[i].info = vars;
		i++;
	}
}

void	init_sem(t_info *vars)
{
	int i;

	i = 0;
	vars->forks = malloc(vars->num_philo * sizeof(sem_t));
	if (!vars->forks)
		return ;
	while (i < vars->num_philo)
	{
		vars->forks[i] = *sem_open("/semaphore", O_CREAT, 0644, 1);
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
	//initilze the forks with semaphore using semaphore open
	init_sem(&vars);
	init_philos(&vars);
	start_action(&vars);
	return (0);
}