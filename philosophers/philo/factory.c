/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:35:11 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 16:23:29 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_factory(t_args *args)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&args->start_line);
	while (i < args->number_of_philosophers)
	{
		if (pthread_create(&args->philos[i]->thread, NULL, \
		philo_lifecycle, args->philos[i]))
			return (1);
		i += 1;
		usleep(WAIT);
	}
	args->start_time = get_time();
	if (pthread_create(&args->monitor, NULL, monitoting, args))
		return (1);
	pthread_mutex_unlock(&args->start_line);
	return (0);
}

int	philo_cleaner(t_args *args)
{
	int		i;
	void	*monitor;

	monitor = NULL;
	i = 0;
	if (pthread_join(args->monitor, &monitor))
		return (1);
	usleep(WAIT);
	while (i < args->number_of_philosophers)
	{
		if (pthread_join(args->philos[i]->thread, NULL))
			return (1);
		i += 1;
		usleep(WAIT);
	}
	return (0);
}

void	*philo_lifecycle(void *philo)
{
	t_philo *const	ph = (t_philo *)philo;

	pthread_mutex_lock(&ph->args->start_line);
	pthread_mutex_unlock(&ph->args->start_line);
	no_country_for_solo_philo(ph);
	if (ph->idx % 2 == 0)
		while (get_time() < ph->args->start_time + ph->args->time_to_eat)
			usleep(WAIT);
	while (1)
	{
		usleep(WAIT);
		if (anyone_dead(ph->args))
			break ;
		if (eating(ph) || anyone_dead(ph->args))
			break ;
		if (sleeping(ph) || usleep(WAIT))
			break ;
		if (thinking(ph))
			break ;
	}
	return (philo);
}

void	no_country_for_solo_philo(t_philo *philo)
{
	const long	now = get_time();

	if (philo->left == philo->right)
	{
		set_variable(&philo->left->mutex, &philo->left->status, 1);
		print_msg(philo, "has taken a fork");
		while (get_time() <= now + philo->args->time_to_die)
			usleep(WAIT);
	}
	usleep(WAIT);
}
