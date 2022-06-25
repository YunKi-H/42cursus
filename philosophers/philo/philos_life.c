/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:32:26 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 23:32:43 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_lifecycle(void *philo)
{
	t_philo *const	ph = (t_philo *)philo;

	if (ph->idx % 2 == 0)
		usleep(100);
	while (1)
	{
		if (eating(ph) || ph->args->game_over)
			break ;
		if (sleeping(ph) || ph->args->game_over)
			break ;
		if (thinking(ph) || ph->args->game_over)
			break ;
		usleep(100);
	}
	return (philo);
}

int	eating(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->left->mutex) || \
	print_msg(philo, "has taken a fork"))
		return (1);
	if (pthread_mutex_lock(&philo->right->mutex) || \
	print_msg(philo, "has taken a fork"))
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
