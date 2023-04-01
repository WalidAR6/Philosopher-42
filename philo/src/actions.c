/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:18:20 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/01 02:34:47 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_eating(t_philo *vars, int i)
{
	put_logs(vars, printf, i, "is eating");
	usleep(vars->info->tte*1000);
}

void	is_thinking(t_philo *vars, int i)
{
	put_logs(vars, printf, i, "is thinking");
	usleep(1000);
}
