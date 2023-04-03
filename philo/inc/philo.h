/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:38:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/03 04:06:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*Include Librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

/*Declare Structs*/
typedef struct s_info
{
	int				num_philo;
	unsigned long 	ttd;
	unsigned long 	tte;
	unsigned long 	tts;
	int				num_to_eat;
	struct s_philo	*th;
	int				*res;
	pthread_mutex_t	*fork;
	pthread_mutex_t print;
}				t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		th;
	unsigned long	last_eat;
	int				left_fork;
	int				right_fork;
	t_info			*info;
}				t_philo;

/*Link Functions*/
int		parser(char **av);
int		philo_args(t_info *vars, int ac, char **av);
int		ft_atoi(const char *str);
void	create_philos(t_info *info);
void	*routine(void *arg);
void	init_mutex(t_info *info);
void	destroy_mutex(t_info *info);
void    put_logs(t_philo *vars, int (*f)(const char *,...), int i, char *str);
void	is_eating(t_philo *vars, int i);
void	is_thinking(t_philo *vars, int i);
void	is_sleeping(t_philo *vars, int i);
int		is_dead(t_info	*vars);

#endif