/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:02:46 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/12 11:26:10 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// typedef struct s_stack
// {
// 	struct s_stack	*prev;
// 	ssize_t		value;
// 	struct s_stack	*next;
// }	t_stack;

t_stack	*ft_stack_new(ssize_t value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error(MALLOC_FAILED);
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

size_t	ft_stack_push(t_stack **top, t_stack *new)
{
	t_stack	*tmp;
	size_t	size;

	size = 0;
	if (*top)
	{
		tmp = *top;
		if (tmp->value == new->value)
			ft_error(IS_DUPLICATED);
		while (tmp->next != *top)
		{
			if (tmp->value == new->value)
				ft_error(IS_DUPLICATED);
			tmp = tmp->next;
		}
	}
	else
	{
		*top = new;
		size = 1;
	}
	return (size);
}
