/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:21 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/23 16:56:01 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args *const	args = (t_args *)malloc(sizeof(t_args));

	if (argc < 5 || argc > 6)
	{
		write(2, "USAGE: ./philo ", 16);
		write(2, "[number_of_philosophers] ", 26);
		write(2, "[time_to_die] ", 15);
		write(2, "[time_to_eat] ", 15);
		write(2, "[time_to_sleep] ", 17);
		write(2, "(number_of_times_each_philosopher_must_eat)\n", 45);
		return (1);
	}
	if (init_args(args, argc, argv))
		return (write(2, "FATAL ERROR\n", 13));
	return (0);
}

int	init_args(t_args *args, int argc, char *argv[])
{
	if (!args)
		return (1);
	memset(args, 0, sizeof(t_args));
	args->number_of_philosophers = verify_arg(argv[1]);
	args->time_to_die = verify_arg(argv[2]);
	args->time_to_eat = verify_arg(argv[3]);
	args->time_to_sleep = verify_arg(argv[4]);
	if (argc == 6)
		args->number_of_times_each_philosopher_must_eat = verify_arg(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = INT32_MAX;
	if (!args->number_of_philosophers || \
	!args->time_to_die || \
	!args->time_to_eat || \
	!args->time_to_sleep || \
	!args->number_of_times_each_philosopher_must_eat)
		return (1);
	args->start_time = get_time();
	if (init_forks(args->forks, args->number_of_philosophers))
		return (1);
	if (init_philos(args, args->number_of_philosophers))
		return (1);
	args->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *));
	if (!args->print)
		return (1);
	return (0);
}

int	init_forks(t_fork **forks, int number_of_philosophers)
{
	int		i;

	forks = (t_fork **)malloc(number_of_philosophers * sizeof(t_fork));
	if (!forks)
		return (1);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (init_fork(forks[i], i))
			return (1);
		i += 1;
	}
	return (0);
}

int	init_fork(t_fork *fork, int i)
{
	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (1);
	fork->idx = i;
	fork->status = 0;
	fork->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *));
	if (!fork->mutex)
		return (1);
	if (pthread_mutex_init(fork->mutex, NULL) < 0)
		return (1);
	return (0);
}

int	init_philos(t_args *args, int number_of_philosophers)
{
	int		i;

	args->philos = (t_philo **)malloc(number_of_philosophers * sizeof(t_philo));
	if (!args->philos)
		return (1);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (init_philo(args, args->philos[i], i, number_of_philosophers))
			return (1);
		i += 1;
	}
	return (0);
}

int	init_philo(t_args *args, t_philo *philo, int i, int number_of_philosophers)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->idx = i;
	philo->last_meal = 0;
	philo->eat_count = 0;
	philo->left = args->forks[(i + number_of_philosophers - 1) % number_of_philosophers];
	philo->right = args->forks[i];
	philo->args = args;
	return (0);
}

int	verify_arg(char *arg)
{
	int	value;

	if (!isnum(arg))
		return (0);
	value = ft_atoi(arg);
	if (value <= 0)
		return (0);
	return (value);
}

int	isnum(char *str)
{
	if (*str == '+' || *str == '-')
		str += 1;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str += 1;
	}
	return (1);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	philo_factory(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_create(args->philos[i]->thread, NULL, philo_lifecycle, args->philos[i]))
			return (1); // thread_create_fail
	}
	if (pthread_create(args->monitor, NULL, monitoting, args))
		return (1); // thread_create_fail
	if (pthread_join(*args->monitor, NULL))
		return (1); // thread_join_fail
	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_join(*args->philos[i]->thread, NULL))
			return (1); // thread_join_fail
	}
	return (0);
}

void	*philo_lifecycle(void *philo)
{
	philo = (t_philo *)philo;
	while (1)
	{

	}
	return (philo);
}

int	eating(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left->mutex))
		return (1);
	if (pthread_mutex_lock(philo->right->mutex))
		return (1);
	philo->left->status = 1;
	philo->right->status = 1;
	philo->last_meal = get_time();
	philo->eat_count += 1;
	while (get_time() < philo->args->start_time + philo->args->time_to_eat)
		usleep(100);
	philo->left->status = 0;
	philo->right->status = 0;
	if (pthread_mutex_unlock(philo->right->mutex))
		return (1);
	if (pthread_mutex_unlock(philo->left->mutex))
		return (1);
	return (0);
}

void	*monitoting(void *args)
{
	return (args);
}
