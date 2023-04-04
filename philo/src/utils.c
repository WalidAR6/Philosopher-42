/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:54:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/04 15:29:34 by waraissi         ###   ########.fr       */
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

// void	my_usleep(t_info *vars, unsigned long mic_sec)
// {
// 	unsigned long current;
// 	unsigned long big_part;
// 	unsigned long sml_part;
	
// 	big_part = (mic_sec / 10) * 7;
// 	sml_part = mic_sec - big_part;
// 	usleep(big_part * 1000);
// 	current = get_time(vars);
// 	while (1)
// 	{
// 		if (get_time(vars) - current >= sml_part)
// 			break ;
// 		usleep(50);
// 	}
// }
