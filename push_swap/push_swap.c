/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:20:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 15:39:42 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 2)
		exit(0);
	ft_stack_init(&a);
	ft_stack_init(&b);
	ft_parse(a, argc, argv);
	// ft_push(a, b);
	ft_atob(a, b);
	ft_btoa(a, b);

	// t_node *tmp;
	// tmp = a->head;
	// while (tmp && tmp->next != a->head)
	// {
	// 	printf("atmp->value : %zd\n", tmp->value);
	// 	// printf("atmp->index : %zd\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// if (tmp)
	// {
	// 	printf("atmp->value : %zd\n", tmp->value);
	// 	// printf("atmp->index : %zd\n", tmp->index);
	// 	printf("a->size : %zu\n", a->size);
	// }
	// else
	// 	printf("a is empty\n");

	// tmp = b->head;
	// while (tmp && tmp->next != b->head)
	// {
	// 	printf("btmp->value : %zd\n", tmp->value);
	// 	// printf("btmp->index : %zd\n", tmp->index);
	// 	tmp = tmp->next;
	// }
	// if (tmp)
	// {
	// 	printf("btmp->value : %zd\n", tmp->value);
	// 	// printf("btmp->index : %zd\n", tmp->index);
	// 	printf("b->size : %zu\n", b->size);
	// }
	// else
	// 	printf("b is empty\n");

	return (0);
}

void	ft_error(int err)
{
	write(2, "Error\n", 6);
	exit(err);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

ssize_t	ft_atol(const char *str)
{
	long long	result;
	long long	positive;

	positive = 1;
	result = 0;
	while (ft_isspace(*str))
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

int	ft_isnum(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int	ft_isint(long long num)
{
	return (num >= INT_MIN && num <= INT_MAX);
}

void	ft_parse(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	ssize_t	value;
	char	**strs;

	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i++], ' ');
		j = 0;
		if(!*strs)
			ft_error(IS_NOT_NUM);
		while (strs[j])
		{
			if (!ft_isnum(strs[j]))
				ft_error(IS_NOT_NUM);
			value = ft_atol(strs[j]);
			if (!ft_isint(value))
				ft_error(IS_NOT_INT);
			ft_stack_push(a, ft_node_new(value));
			j++;
		}
		free(strs);
	}
}

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
	//add_new_node_back
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
	return(new);
}

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

void	ft_arg_case3(t_stack *a, t_stack *b)
{
	size_t	idx;

	if (a->size == 2)
	{
		write(1, "sa\n", 3);
		exit(0);
	}
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
		if (a->head->next->index == idx)
			write(1, "ra\n", 3);
		else
			write(1, "sa\nrra\n", 7);
	if (!b->size)
		exit(0);
}

void	ft_arg_case45(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->index < 2)
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

void	ft_atob(t_stack *a, t_stack *b)
{
	size_t	precision;
	size_t	pivot;

	precision = ft_get_precision(a->size);
	if (ft_issorted(a))
		exit(0);
	if (a->size <= 3)
		ft_arg_case3(a, b);
	else if (a->size <= 5)
		ft_arg_case45(a, b);
	else
	{
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
}

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

void	ft_btoa(t_stack *a, t_stack *b)
{
	size_t	half;
	size_t	maxidx;
	t_node	*tmp;
	size_t	i;

	while (b->size)
	{
		half = b->size / 2;
		maxidx = b->size - 1;
		tmp = b->head;
		i = 0;
		while (tmp->next != b->head)
		{
			if (tmp->index == maxidx)
				break;
			i++;
			tmp = tmp->next;
		}
		if (i <= half)
			while (b->head->index != maxidx)
				ft_rotate(b, "rb\n");
		else
			while (b->head->index != maxidx)
				ft_rev_rotate(b, "rrb\n");
		ft_push(b, a, "pa\n");
	}
}
