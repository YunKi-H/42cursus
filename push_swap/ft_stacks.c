/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:26:54 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 16:27:48 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_stack_init(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_error(MALLOC_FAILED);
	(*stack)->head = NULL;
	(*stack)->size = 0;
}

void	ft_node_compare(t_node *exist, t_node *new)
{
	if (exist->value == new->value)
		ft_error(IS_OVERLAPPED);
	else if (exist->value > new->value)
		exist->index += 1;
	else
		new->index += 1;
}

void	ft_stack_push(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	if (!stack->head)
	{
		stack->head = new;
		stack->size += 1;
		return ;
	}
	tmp = stack->head;
	while (tmp->next != stack->head)
	{
		ft_node_compare(tmp, new);
		tmp = tmp->next;
	}
	ft_node_compare(tmp, new);
	tmp->next = new;
	new->prev = tmp;
	new->next = stack->head;
	stack->head->prev = new;
	stack->size += 1;
}

t_node	*ft_node_new(ssize_t value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_error(MALLOC_FAILED);
	new->value = value;
	new->index = 0;
	new->prev = new;
	new->next = new;
	return (new);
}
