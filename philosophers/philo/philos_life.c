/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:32:26 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 12:34:41 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(t_philo *philo)
{
	int	ready;

	ready = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->left->mutex);
		pthread_mutex_lock(&philo->right->mutex);
		if (!philo->left->status && !philo->right->status)
		{
			if (anyone_dead(philo->args))
				return (1);
			philo->left->status = 1;
			print_msg(philo, "has taken a fork");
			philo->right->status = 1;
			print_msg(philo, "has taken a fork");
			ready = 1;
		}
		pthread_mutex_unlock(&philo->left->mutex);
		pthread_mutex_unlock(&philo->right->mutex);
		if (ready)
			return (0);
		usleep(WAIT);
	}
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->mutex);
	pthread_mutex_lock(&philo->right->mutex);
	philo->left->status = 0;
	philo->right->status = 0;
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
}

int	eating(t_philo *philo)
{
	if (grab_fork(philo))
		return (1);
	philo->last_meal = get_time();
	philo->eat_count += 1;
	if (anyone_dead(philo->args))
		return (1);
	print_msg(philo, "is eating");
	while (get_time() < philo->last_meal + philo->args->time_to_eat)
		usleep(WAIT);
	put_down_fork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	const long	now = get_time();

	if (anyone_dead(philo->args))
		return (1);
	print_msg(philo, "is sleeping");
	while (get_time() < now + philo->args->time_to_sleep)
		usleep(WAIT);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (anyone_dead(philo->args))
		return (1);
	print_msg(philo, "is thinking");
	return (0);
}
