/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:38:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/31 15:42:54 by waraissi         ###   ########.fr       */
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
	int				*res;
}				t_info;

typedef struct s_philo
{
	int			id;
	pthread_t	th;
	t_info		info;
}				t_philo;


/*Link Functions*/
int		parser(char **av);
int		philo_args(t_info *vars, int ac, char **av);
int		ft_atoi(const char *str);

#endif