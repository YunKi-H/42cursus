/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:21 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 21:35:55 by yuhwang          ###   ########.fr       */
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
		return (write(2, "FATAL ERROR_init\n", 17));
	if (philo_factory(args))
		return (write(2, "FATAL ERROR_philo_factory\n", 26));
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
	args->monitor = NULL;
	if (!args->number_of_philosophers || \
	!args->time_to_die || \
	!args->time_to_eat || \
	!args->time_to_sleep || \
	!args->number_of_times_each_philosopher_must_eat)
		return (1);
	args->start_time = get_time();
	if (init_forks(args, args->number_of_philosophers))
		return (1);
	if (init_philos(args, args->number_of_philosophers))
		return (1);
	if (pthread_mutex_init(&args->print, NULL) < 0)
		return (1);
	return (0);
}

int	init_forks(t_args *args, int number_of_philosophers)
{
	int		i;

	args->forks = (t_fork **)malloc(number_of_philosophers * sizeof(t_fork));
	if (!args->forks)
		return (1);
	i = 0;
	while (i < number_of_philosophers)
	{
		args->forks[i] = init_fork(i);
		if (!args->forks[i])
			return (1);
		i += 1;
	}
	return (0);
}

t_fork	*init_fork(int i)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->idx = i;
	fork->status = 0;
	if (pthread_mutex_init(&fork->mutex, NULL) < 0)
		return (NULL);
	return (fork);
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
		args->philos[i] = init_philo(args, i, number_of_philosophers);
		if (!args->philos[i])
			return (1);
		i += 1;
	}
	return (0);
}

t_philo	*init_philo(t_args *args, int i, int number_of_philosophers)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->thread = NULL;
	philo->idx = i;
	philo->last_meal = get_time();
	philo->eat_count = 0;
	philo->left = args->forks[(i + number_of_philosophers - 1) % number_of_philosophers];
	philo->right = args->forks[i];
	philo->args = args;
	return (philo);
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
	int		i;
	void	*monitor;

	monitor = NULL;
	i = 0;
	// printf("1\n");
	while (i < args->number_of_philosophers)
	{
		// printf("2 %d\n", i);
		if (pthread_create(&args->philos[i]->thread, NULL, philo_lifecycle, args->philos[i]))
			return (1);
		i += 1;
	}
	// printf("3\n");
	if (pthread_create(&args->monitor, NULL, monitoting, args))
		return (1);
	// printf("4\n");
	if (pthread_join(args->monitor, &monitor))
		return (1);
	// printf("5\n");
	i = 0;
	while (i < args->number_of_philosophers)
	{
		// printf("6 %d\n", i);
		if (pthread_join(args->philos[i]->thread, NULL))
			return (1);
		i += 1;
	}
	// printf("7\n");
	if (monitor)
		print_msg((t_philo *)monitor, "died");
	return (0);
}

void	*philo_lifecycle(void *philo)
{
	t_philo *const	ph = (t_philo *)philo;

	// printf("lifecycle(philo[%d])\n", ph->idx);
	if (ph->idx % 2 == 0)
		usleep(100);
	while (1)
	{
		// printf("eating(philo[%d])\n", ph->idx);
		if (eating(ph) || ph->args->game_over)
			break ;
		// printf("sleeping(philo[%d])\n", ph->idx);
		if (sleeping(ph) || ph->args->game_over)
			break ;
		// printf("thinking(philo[%d])\n", ph->idx);
		if (thinking(ph) || ph->args->game_over)
			break ;
		usleep(100);
	}
	return (philo);
}

int	eating(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->left->mutex) || print_msg(philo, "has taken a fork"))
		return (1);
	if (pthread_mutex_lock(&philo->right->mutex) || print_msg(philo, "has taken a fork"))
		return (1);
	philo->left->status = 1;
	philo->right->status = 1;
	philo->last_meal = get_time();
	philo->eat_count += 1;
	if (print_msg(philo, "is eating"))
		return (1);
	while (get_time() < philo->last_meal + philo->args->time_to_eat)
		usleep(100);
	philo->left->status = 0;
	philo->right->status = 0;
	if (pthread_mutex_unlock(&philo->left->mutex))
		return (1);
	if (pthread_mutex_unlock(&philo->right->mutex))
		return (1);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_msg(philo, "is sleeping"))
		return (1);
	while (get_time() < philo->args->start_time + philo->args->time_to_sleep)
		usleep(100);
	return (0);
}

int	thinking(t_philo *philo)
{
	return (print_msg(philo, "is thinking"));
}


void	*monitoting(void *args)
{
	t_args *const	arg = (t_args *)args;
	int				i;
	int				true_ending;

	while (1)
	{
		true_ending = 1;
		i = 0;
		while (i < arg->number_of_philosophers)
		{
			if (get_time() - arg->philos[i]->last_meal > arg->time_to_die)
			{
				arg->game_over = 1;
				return ((void *)arg->philos[i]);
			}
			if (arg->philos[i++]->eat_count < arg->number_of_times_each_philosopher_must_eat)
				true_ending = 0;
		}
		if (true_ending)
		{
			arg->game_over = 1;
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

int	print_msg(t_philo *philo, const char *msg)
{
	if (pthread_mutex_lock(&philo->args->print))
		return (1);
	printf(
		"[%ldms] %d %s\n", \
		get_time() - philo->args->start_time, \
		philo->idx + 1, \
		msg
		);
	if (pthread_mutex_unlock(&philo->args->print))
		return (1);
	return (0);
}
