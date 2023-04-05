/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:54:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/05 16:18:18 by waraissi         ###   ########.fr       */
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
	unsigned long	b_time;
	unsigned long	s_time;

	b_time = (mic_sec / 10) * 9;
	s_time = mic_sec - b_time;
	usleep(b_time * 1000);	
	while (get_time(vars)< s_time)
	{
		sleep(10);
	}
}
