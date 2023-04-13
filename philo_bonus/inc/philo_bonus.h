/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:21:57 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/13 02:02:28 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/*Include Librairies*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <semaphore.h>

/*Declare Structs*/
typedef struct s_info
{
	int				ac;
	int				num_philo;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	time_t			start_time;
	int				num_to_eat;
	sem_t			*forks;
	sem_t			*print;
	struct s_philo	*philos;
}				t_info;

typedef struct s_philo
{
	int			id;
	pid_t		ph;
	pthread_t	helper;
	time_t		last_eat;
	int			is_died;
	int			num_of_eat;
	t_info		*info;
}				t_philo;

/*Link Functions*/
int		parser(char **av);
int		philo_args(t_info *vars, int ac, char **av);
int		ft_atoi(const char *str);
time_t	ft_atoi_t(char *str);
void	put_logs(t_philo *vars, int i, char *str);
time_t	get_time(void);
void	my_usleep(time_t mic_sec);

#endif