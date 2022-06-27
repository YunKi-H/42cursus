/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:19:50 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 12:21:26 by yuhwang          ###   ########.fr       */
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

# define WAIT 200

typedef struct s_args		t_args;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;
typedef struct s_monitor	t_monitor;

struct s_args
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	long			start_time;
	pthread_mutex_t	start_line;
	int				game_over;
	pthread_mutex_t	someone_dead;
	pthread_mutex_t	print;
	t_fork			**forks;
	t_philo			**philos;
	pthread_t		monitor;
};

struct s_philo
{
	pthread_t	thread;
	int			idx;
	long		last_meal;
	int			eat_count;
	t_fork		*left;
	t_fork		*right;
	t_args		*args;
};

struct s_fork
{
	int				idx;
	int				status;
	pthread_mutex_t	mutex;
};

// init
int		init_args(t_args *args, int argc, char *argv[]);
int		init_forks(t_args *args, int number_of_philosophers);
t_fork	*init_fork(int i);
int		init_philos(t_args *args, int number_of_philosophers);
t_philo	*init_philo(t_args *args, int i, int number_of_philosophers);
// philo's life
int		philo_factory(t_args *args);
int		philo_cleaner(t_args *args);
void	*philo_lifecycle(void *philo);
void	no_country_for_solo_philo(t_philo *philo);
void	*monitoting(void *args);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
// utils
int		ft_atoi(const char *str);
int		verify_arg(char *arg);
long	get_time(void);
void	*set_variable(pthread_mutex_t *mutex, int *varp, int value);
void	print_msg(t_philo *philo, const char *msg);
// bool
int		isnum(char *str);
int		is_valid_args(t_args *args);
int		anyone_dead(t_args *args);

#endif
