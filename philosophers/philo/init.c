/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:33:13 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 23:30:17 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		args->times_to_eat = verify_arg(argv[5]);
	else
		args->times_to_eat = INT32_MAX;
	args->start_time = get_time();
	if (!args->number_of_philosophers || \
	!args->time_to_die || \
	!args->time_to_eat || \
	!args->time_to_sleep || \
	!args->times_to_eat)
		return (1);
	if (pthread_mutex_init(&args->print, NULL) < 0)
		return (1);
	if (init_forks(args, args->number_of_philosophers))
		return (1);
	if (init_philos(args, args->number_of_philosophers))
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

t_philo	*init_philo(t_args *args, int i, int number_of_philos)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->thread = NULL;
	philo->idx = i;
	philo->last_meal = get_time();
	philo->eat_count = 0;
	philo->left = args->forks[(i + number_of_philos - 1) % number_of_philos];
	philo->right = args->forks[i];
	philo->args = args;
	return (philo);
}
