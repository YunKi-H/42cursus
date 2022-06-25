/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:35:11 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 23:38:49 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_factory(t_args *args)
{
	int		i;
	void	*monitor;

	monitor = NULL;
	i = -1;
	while (++i < args->number_of_philosophers)
	{
		if (pthread_create(&args->philos[i]->thread, NULL, \
		philo_lifecycle, args->philos[i]))
			return (1);
	}
	if (pthread_create(&args->monitor, NULL, monitoting, args))
		return (1);
	if (pthread_join(args->monitor, &monitor))
		return (1);
	i = -1;
	while (++i < args->number_of_philosophers)
	{
		if (pthread_join(args->philos[i]->thread, NULL))
			return (1);
	}
	if (monitor)
		return (print_msg((t_philo *)monitor, "died"));
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
			if (get_time() - arg->philos[i]->last_meal > arg->time_to_die)
			{
				arg->game_over = 1;
				return ((void *)arg->philos[i]);
			}
			if (arg->philos[i]->eat_count < arg->times_to_eat)
				true_ending = 0;
		}
		if (true_ending)
		{
			arg->game_over = 1;
			return (NULL);
		}
		usleep(100);
	}
}
