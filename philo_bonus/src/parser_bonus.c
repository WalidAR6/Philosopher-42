/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:25:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/15 02:52:31 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	philo_args(t_info *vars, int ac, char **av)
{
	vars->ac = ac;
	vars->num_philo = ft_atoi(av[1]);
	vars->ttd = ft_atoi_t(av[2]);
	vars->tte = ft_atoi_t(av[3]);
	vars->tts = ft_atoi_t(av[4]);
	vars->num_to_eat = -2;
	if (ac == 6)
		vars->num_to_eat = ft_atoi(av[5]);
	vars->start_time = get_time();
	vars->count = 0;
	if (vars->num_philo == -1 || !vars->ttd
		|| !vars->tts || !vars->tte || vars->num_to_eat == -1)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	return (1);
}

int	parser(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
