/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:51:50 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/19 13:59:20 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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

void	send_bit(int pid, int bit)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	else
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_char(int pid, int c)
{
	send_bit(pid, c & 0b10000000);
	send_bit(pid, c & 0b01000000);
	send_bit(pid, c & 0b00100000);
	send_bit(pid, c & 0b00010000);
	send_bit(pid, c & 0b00001000);
	send_bit(pid, c & 0b00000100);
	send_bit(pid, c & 0b00000010);
	send_bit(pid, c & 0b00000001);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi((const char *)argv[1]);
		if (pid <= 0 || pid > 100000)
		{
			write(2, "INVALID PID\n", 13);
			exit(1);
		}
		i = 0;
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i += 1;
		}
		send_char(pid, '\n');
	}
	else
		write(1, "USAGE : ./client [PID] [MESSAGE]\n", 34);
	return (0);
}
