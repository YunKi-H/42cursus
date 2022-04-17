/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:44:59 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 15:52:23 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_push(t_stack *from, t_stack *to, const char *oper)
{
	from->head->prev->next = from->head->next;
	from->head->next->prev = from->head->prev;
	if (!to->head)
	{
		to->head = from->head;
		from->head = from->head->next;
		to->head->next = to->head;
		to->head->prev = to->head;
	}
	else
	{
		to->head->prev->next = from->head;
		from->head = from->head->next;
		to->head->prev->next->prev = to->head->prev;
		to->head->prev->next->next = to->head;
		to->head->prev = to->head->prev->next;
		to->head = to->head->prev;
	}
	from->size -= 1;
	to->size += 1;
	if (!from->size)
		from->head = NULL;
	write(1, oper, 3);
}

void	ft_rotate(t_stack *stack, const char *oper)
{
	stack->head = stack->head->next;
	write(1, oper, 3);
}

void	ft_rev_rotate(t_stack *stack, const char *oper)
{
	stack->head = stack->head->prev;
	write(1, oper, 4);
}
