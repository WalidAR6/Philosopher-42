/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:13:53 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/09 02:04:54 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
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

time_t	ft_atotime(char *str)
{
	time_t		i;
	time_t		tmp;
	time_t		res;

	i = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
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
