/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:21 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/22 01:13:54 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	*args;
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
	args = init_args(argc, argv);
	if (!args)
		return (write(2, "FATAL ERROR\n", 13));
	return (0);
}

t_args	*init_args(int argc, char *argv[])
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
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
		return (NULL);
	args->forks = init_forks(args->number_of_philosophers);
	if (!args->forks)
		return (NULL);
	args->philos = init_philos(args->forks, args->number_of_philosophers);
	if (!args->philos)
		return (NULL);
	return (args);
}

t_fork	**init_forks(int number_of_philosophers)
{
	t_fork	**forks;
	int		i;

	forks = (t_fork **)malloc(number_of_philosophers * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		forks[i] = init_fork(i);
		if (!forks[i])
			return (NULL);
		i += 1;
	}
	return (forks);
}

t_fork	*init_fork(int i)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->idx = i;
	fork->status = 0;
	fork->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *));
	if (!fork->mutex)
		return (NULL);
	if (pthread_mutex_init(fork->mutex, NULL) < 0)
		return (NULL);
	return (fork);
}

t_philo	**init_philos(t_fork **forks, int number_of_philosophers)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)malloc(number_of_philosophers * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		philos[i] = init_philo(forks, i, number_of_philosophers);
		if (!philos[i])
			return (NULL);
		i += 1;
	}
	return (philos);
}

t_philo	*init_philo(t_fork **forks, int	i, int number_of_philosophers)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->idx = i;
	philo->last_meal = 0;
	philo->eat_count = 0;
	philo->left = forks[(i + number_of_philosophers - 1) % number_of_philosophers];
	philo->right = forks[i];
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
