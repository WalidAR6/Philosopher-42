/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:23:51 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/14 02:40:26 by waraissi         ###   ########.fr       */
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
	exit(0);
}

// int		check_death(t_philo *vars, time_t last_eat)
// {
// 	if (get_time() - last_eat > vars->info->ttd)
// 		return (1);
// 	return (0);	
// }
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
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}

void	routine(t_philo *vars)
{
	pthread_create(&vars->helper, NULL, &func, vars);
	pthread_detach(vars->helper);
	while (!vars->is_died)
	{
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
	exit(0);
}


void	init_threads(t_philo *vars)
{
	pthread_create(&vars->helper, NULL, &func, vars);
	pthread_detach(vars->helper);
}

void	child_p(t_philo *vars)
{
	routine(vars);
	// init_threads(vars); 
}

void	start_action(t_info *vars)
{
	int i;

	i = 0;
	vars->start_time = get_time();
	while (i < vars->num_philo)
	{
		vars->philos[i].ph = fork();
		if (vars->philos[i].ph == 0)
			child_p(&vars->philos[i]);
		i++;
	}
	waitpid(-1, NULL, 0);
	kill_p(vars);
}

void	init(t_info *vars)
{
	int	i;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

	i = 0;
	vars->forks = sem_open("/sema", O_CREAT | O_EXCL, 0644, vars->num_philo);
	vars->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
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

int	main(int ac, char **av)
{
	t_info	vars;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	sem_unlink("/sema");
	sem_unlink("/print");
	if (!parser(av) || !philo_args(&vars, ac, av))
		return (1);
	init(&vars);
	start_action(&vars);
	sem_close(vars.forks);
	sem_close(vars.print);
	sem_unlink("/sema");
	sem_unlink("/print");
	return (0);
}
