/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:34:18 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 22:35:19 by yuhwang          ###   ########.fr       */
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

int	print_msg(t_philo *philo, const char *msg)
{
	if (pthread_mutex_lock(&philo->args->print))
		return (1);
	printf(
		"[%ldms] %d %s\n", \
		get_time() - philo->args->start_time, \
		philo->idx + 1, \
		msg
		);
	if (pthread_mutex_unlock(&philo->args->print))
		return (1);
	return (0);
}
