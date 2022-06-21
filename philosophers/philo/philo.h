/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:19:50 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/22 01:07:14 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
//write, usleep
# include <stdlib.h>
//malloc, free
# include <string.h>
//memset
# include <stdio.h>
//printf
# include <pthread.h>
//pthread_create, pthread_detach, pthread_join
//pthread_mutex_init, pthread_mutex_destroy
//pthread_mutex_lock, pthread_mutex_unlock
# include <sys/time.h>
//gettimeofday

typedef struct s_args t_args;
typedef struct s_philo t_philo;
typedef struct s_fork t_fork;
typedef struct s_monitor t_monitor;

struct s_args
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_fork			**forks;
	t_philo			**philos;
	t_monitor		*monitor;
};

struct s_philo
{
	int		idx;
	int		last_meal;
	int		eat_count;
	t_fork	*left;
	t_fork	*right;
};

struct s_fork
{
	int				idx;
	int				status;
	pthread_mutex_t	*mutex;
};

struct s_monitor
{

};

t_args	*init_args(int argc, char *argv[]);
t_fork	**init_forks(int number_of_philosophers);
t_fork	*init_fork(int i);
t_philo	**init_philos(t_fork **forks, int number_of_philosophers);
t_philo	*init_philo(t_fork **forks, int	i, int number_of_philosophers);
int	ft_atoi(const char *str);
int	isnum(char *str);
int	verify_arg(char *arg);

#endif
