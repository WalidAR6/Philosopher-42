/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:54:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/06 15:55:13 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	get_time(t_info *vars)
{
	unsigned long	l;

	gettimeofday(&vars->time, NULL);
	l = (vars->time.tv_sec * 1000) + (vars->time.tv_usec / 1000);
	return (l);
}

void	my_usleep(t_info *vars, unsigned long mic_sec)
{
	unsigned long current;

	current = get_time(vars);
	while (get_time(vars) - current < mic_sec)
		usleep(10);
}
