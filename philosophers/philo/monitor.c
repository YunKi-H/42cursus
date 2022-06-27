/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:37:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 15:38:32 by yuhwang          ###   ########.fr       */
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
			if (get_time() > arg->philos[i]->last_meal + arg->time_to_die)
			{
				set_variable(&arg->someone_dead, &arg->game_over, 1);
				print_dying_msg(arg->philos[i], "died");
				return ((void *)arg->philos[i]);
			}
			if (arg->philos[i]->eat_count < arg->times_to_eat)
				true_ending = 0;
			usleep(WAIT);
		}
		if (true_ending)
			return (set_variable(&arg->someone_dead, &arg->game_over, 1));
	}
}
