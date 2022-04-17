/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:46:58 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 16:32:58 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_issorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next != stack->head)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

size_t	ft_get_precision(size_t n)
{
	size_t	root;

	root = 2;
	while (root * root < n)
		root += 1;
	return (root / 2);
}

void	ft_atob(t_stack *a, t_stack *b)
{
	if (ft_issorted(a))
		exit(0);
	if (a->size == 2)
		ft_arg_case2();
	else if (a->size == 3)
		ft_arg_case3(a, b);
	else if (a->size <= 5)
		ft_arg_case45(a, b);
	else
		ft_arg_else(a, b);
}
