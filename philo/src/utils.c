/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:54:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/07 08:29:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	get_time(void)
{
	unsigned long	l;
	struct timeval	time;

	gettimeofday(&time, NULL);
	l = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (l);
}

void	my_usleep(unsigned long mic_sec)
{
	unsigned long	current;

	current = get_time();
	while (get_time() - current < mic_sec)
		usleep(100);
}
