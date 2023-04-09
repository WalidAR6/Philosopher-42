/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:07 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/09 05:20:11 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->mutex, NULL);
	info->fork = malloc(info->num_philo * sizeof(pthread_mutex_t));
	if (!info->fork)
		return (1);
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	return (0);
}

void	destroy_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->mutex);
}

int	philo_args(t_info *vars, int ac, char **av)
{
	vars->num_philo = ft_atoi(av[1]);
	vars->ttd = ft_atoi_t(av[2]);
	vars->tte = ft_atoi_t(av[3]);
	vars->tts = ft_atoi_t(av[4]);
	vars->num_to_eat = -2;
	if (ac == 6)
		vars->num_to_eat = ft_atoi(av[5]);
	vars->ac = ac;
	vars->start_time = get_time();
	vars->g_death = 0;
	if (vars->num_philo == -1 || !vars->ttd
		|| !vars->tts || !vars->tte || vars->num_to_eat == -1)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	return (1);
}
