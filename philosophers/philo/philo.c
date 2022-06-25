/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:21 by yuhwang           #+#    #+#             */
/*   Updated: 2022/06/25 23:35:08 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args *const	args = (t_args *)malloc(sizeof(t_args));

	if (argc < 5 || argc > 6)
	{
		write(2, "USAGE: ./philo ", 16);
		write(2, "[number_of_philosophers] ", 26);
		write(2, "[time_to_die] ", 15);
		write(2, "[time_to_eat] ", 15);
		write(2, "[time_to_sleep] ", 17);
		write(2, "(number_of_times_each_philosopher_must_eat)\n", 45);
		return (1);
	}
	if (init_args(args, argc, argv))
		return (write(2, "FATAL ERROR\n", 13));
	if (philo_factory(args))
		return (write(2, "FATAL ERROR\n", 13));
	return (0);
}
