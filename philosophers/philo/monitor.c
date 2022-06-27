/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:37:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 18:21:39 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_dying_msg(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&philo->args->print);
	printf(
		"%ld %d %s\n", \
		get_time() - philo->args->start_time, \
		philo->idx + 1, \
		msg
		);
	pthread_mutex_unlock(&philo->args->print);
}

static int	raise_hand_if_dead(t_args *arg, int i)
{
	pthread_mutex_lock(&arg->philos[i]->meal);
	if (get_time() > arg->philos[i]->last_meal + arg->time_to_die)
	{
		set_variable(&arg->someone_dead, &arg->game_over, 1);
		print_dying_msg(arg->philos[i], "died");
		pthread_mutex_unlock(&arg->philos[i]->meal);
		return (1);
	}
	pthread_mutex_unlock(&arg->philos[i]->meal);
	return (0);
}

void	*monitoting(void *args)
{
	t_args *const	arg = (t_args *)args;
	int				i;
	int				true_ending;

	while (1)
	{
		true_ending = 1;
		i = -1;
		while (++i < arg->number_of_philosophers)
		{
			if (raise_hand_if_dead(arg, i))
				return ((void *)arg->philos[i]);
			pthread_mutex_lock(&arg->philos[i]->count);
			if (arg->philos[i]->eat_count < arg->times_to_eat)
				true_ending = 0;
			pthread_mutex_unlock(&arg->philos[i]->count);
			usleep(WAIT);
		}
		if (true_ending)
			return (set_variable(&arg->someone_dead, &arg->game_over, 1));
	}
}
