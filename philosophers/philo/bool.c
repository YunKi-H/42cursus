/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:04:22 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/26 14:17:41 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	anyone_dead(t_args *args)
{
	int	answer;

	answer = 0;
	pthread_mutex_lock(&args->someone_dead);
	if (args->game_over)
		answer = 1;
	pthread_mutex_unlock(&args->someone_dead);
	return (answer);
}

int	is_valid_args(t_args *args)
{
	return (
		args->number_of_philosophers && \
		args->time_to_die && \
		args->time_to_eat && \
		args->time_to_sleep && \
		args->times_to_eat
	);
}
