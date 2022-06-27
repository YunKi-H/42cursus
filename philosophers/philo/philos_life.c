/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:32:26 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 18:55:52 by yuhwang          ###   ########.fr       */
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
			philo->left->status = 1;
			philo->right->status = 1;
			print_msg(philo, "has taken a fork");
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
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal);
	set_variable(&philo->count, &philo->eat_count, philo->eat_count + 1);
	print_msg(philo, "is eating");
	while (get_time() < philo->last_meal + philo->args->time_to_eat)
		usleep(WAIT);
	put_down_fork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	const long	now = get_time();

	print_msg(philo, "is sleeping");
	while (get_time() < now + philo->args->time_to_sleep)
		usleep(WAIT);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
	return (0);
}
