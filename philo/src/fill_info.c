/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:07 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/07 06:19:14 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->print, NULL);
	info->fork = malloc(info->num_philo * sizeof(pthread_mutex_t));
	if (!info->fork)
	{
		free(info->res);
		return (1);
	}
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
}

void	init(t_info *vars, int ac)
{
	vars->num_philo = vars->res[0];
	vars->ttd = vars->res[1];
	vars->tte = vars->res[2];
	vars->tts = vars->res[3];
	vars->num_to_eat = -1;
	if (ac == 6)
		vars->num_to_eat = vars->res[4];
	vars->ac = ac;
	vars->start_time = get_time();
	vars->g_death = 0;
}

int	philo_args(t_info *vars, int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	vars->res = (int *) malloc((ac - 1) * sizeof(int));
	if (!vars->res)
		return (0);
	while (av[++j])
	{
		vars->res[++i] = ft_atoi(av[j]);
		if (vars->res[i] < 0 || vars->res[0] == 0)
		{
			write(2, "Error\n", 7);
			free(vars->res);
			return (0);
		}
	}
	init(vars, ac);
	return (1);
}
