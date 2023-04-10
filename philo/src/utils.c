/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:54:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/10 09:18:28 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	put_logs(t_philo *vars, int i, char *str)
{
	int	g_d;

	pthread_mutex_lock(&vars->info->mutex);
	g_d = vars->info->g_death;
	pthread_mutex_unlock(&vars->info->mutex);
	pthread_mutex_lock(&vars->info->print);
	if (!g_d)
		printf("%ldms\t%d %s\n",
			get_time() - vars->info->start_time, i, str);
	pthread_mutex_unlock(&vars->info->print);
}

time_t	get_time(void)
{
	time_t			l;
	struct timeval	time;

	gettimeofday(&time, NULL);
	l = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (l);
}

void	my_usleep(time_t mil_sec)
{
	time_t	current;
	
	current = get_time();
	while (get_time() - current < mil_sec)
		usleep(100);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res < 0)
			return (-1);
		i++;
	}
	return (res);
}

time_t	ft_atoi_t(char *str)
{
	time_t		i;
	time_t		tmp;
	time_t		res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + str[i] - '0';
		if (res < tmp)
			return (0);
		i++;
	}
	return (res);
}