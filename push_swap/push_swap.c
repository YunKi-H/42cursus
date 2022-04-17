/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:20:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 22:30:14 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		exit(0);
	ft_stack_init(&a);
	ft_stack_init(&b);
	ft_parse(a, argc, argv);
	ft_atob(a, b);
	ft_btoa(a, b);
	return (0);
}

void	ft_error(int err)
{
	write(2, "Error\n", 6);
	exit(err);
}
