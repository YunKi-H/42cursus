/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:33:42 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 15:44:23 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_btoa(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	size_t	i;

	while (b->size)
	{
		tmp = b->head;
		i = 0;
		while (tmp->next != b->head)
		{
			if (tmp->index == b->size - 1)
				break ;
			tmp = tmp->next;
			i++;
		}
		if (i <= b->size / 2)
			while (b->head->index != b->size - 1)
				ft_rotate(b, "rb\n");
		else
			while (b->head->index != b->size - 1)
				ft_rev_rotate(b, "rrb\n");
		ft_push(b, a, "pa\n");
	}
}
