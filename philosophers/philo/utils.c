/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:34:18 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/27 12:21:20 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	positive;

	positive = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive = -positive;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (positive * result);
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

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*set_variable(pthread_mutex_t *mutex, int *varp, int value)
{
	pthread_mutex_lock(mutex);
	*varp = value;
	pthread_mutex_unlock(mutex);
	return (NULL);
}

void	print_msg(t_philo *philo, const char *msg)
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
