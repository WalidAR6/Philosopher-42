/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:21:57 by waraissi          #+#    #+#             */
/*   Updated: 2023/04/10 09:24:32 by waraissi         ###   ########.fr       */
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
	struct s_philo	*philos;
}				t_info;

typedef struct s_philo
{
	int		id;
	pid_t	ph;
	t_info	*info;
}				t_philo;

/*Link Functions*/
int		parser(char **av);
int		philo_args(t_info *vars, int ac, char **av);
int		ft_atoi(const char *str);
time_t	ft_atoi_t(char *str);
void	put_logs(t_philo *vars, int i, char *str);
time_t	get_time(void);
void	my_usleep(unsigned long mic_sec);

#endif