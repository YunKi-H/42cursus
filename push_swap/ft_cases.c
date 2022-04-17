/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:21:58 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 16:32:35 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_arg_case2(void)
{
	write(1, "sa\n", 3);
	exit(0);
}

void	ft_arg_case3(t_stack *a, t_stack *b)
{
	size_t	idx;

	idx = a->size + b->size - 3;
	if (a->head->index == idx)
		write(1, "rra\nsa\n", 7);
	else if (a->head->index == idx + 1)
	{
		if (a->head->next->index == idx)
			write(1, "sa\n", 3);
		else
			write(1, "rra\n", 4);
	}
	else
	{
		if (a->head->next->index == idx)
			write(1, "ra\n", 3);
		else
			write(1, "sa\nrra\n", 7);
	}
	if (!b->size)
		exit(0);
}

void	ft_arg_case45(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->index < a->size + b->size - 3)
			ft_push(a, b, "pb\n");
		else
			ft_rotate(a, "ra\n");
	}
	ft_arg_case3(a, b);
	if (b->size == 1)
		write(1, "pa\n", 3);
	else
	{
		if (!b->head->index)
			write(1, "sb\n", 3);
		write(1, "pa\npa\n", 6);
	}
	exit(0);
}

void	ft_arg_else(t_stack *a, t_stack *b)
{
	size_t	precision;
	size_t	pivot;

	precision = ft_get_precision(a->size);
	pivot = 0;
	while (a->size)
	{
		if (a->head->index <= pivot)
		{
			ft_push(a, b, "pb\n");
			ft_rotate(b, "rb\n");
			pivot += 1;
		}
		else if (a->head->index <= pivot + precision)
		{
			ft_push(a, b, "pb\n");
			pivot += 1;
		}
		else
			ft_rotate(a, "ra\n");
	}
}
