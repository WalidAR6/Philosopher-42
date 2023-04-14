/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:00:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/14 02:30:34 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	put_logs(t_philo *vars, int i, char *str, int index)
{
	int	g_d;

	if (index == 0)
	{
		sem_wait(vars->info->print);
		printf("%ldms\t%d %s\n",
	 		get_time() - vars->info->start_time, i + 1, str);
	}
	else
	{
		sem_wait(vars->info->print);
		g_d = vars->is_died;
		if (!g_d)
			printf("%ldms\t%d %s\n",
				get_time() - vars->info->start_time, i, str);
		sem_post(vars->info->print);
	}
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
	time_t	b_part;
	
	b_part = mil_sec * 9 / 10;
	current = get_time();
	usleep(b_part * 1000);
	while (get_time() - current < mil_sec)
		usleep(100);
}
