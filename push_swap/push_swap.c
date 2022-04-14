/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:20:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/13 16:37:32 by yuhwang          ###   ########.fr       */
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
	// ft_atob(a, b);
	// ft_btoa(a, b);

	t_node *tmp;
	tmp = a->head;
	while (tmp->next != a->head)
	{
		printf("tmp->value : %zd\n", tmp->value);
		tmp = tmp->next;
	}
	printf("tmp->value : %zd\n", tmp->value);
	printf("a->size : %zu\n", a->size);

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

long long	ft_atol(const char *str)
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
		j = 0;
		strs = ft_split(argv[i++], ' ');
		while (strs[j])
		{
			if (ft_isnum(strs[j]))
				value = ft_atol(strs[j]);
			else
				ft_error(IS_NOT_NUM);
			if (ft_isint(value))
				ft_stack_push(a, ft_node_new(value));
			else
				ft_error(IS_NOT_INT);
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
		// printf("tmp->value : %zd\n", tmp->value);
		// printf("new->value : %zd\n", new->value);
		// printf("%zu\n", stack->size);
		if (tmp->value == new->value)
			ft_error(IS_OVERLAPPED);
		tmp = tmp->next;
	}
	if (tmp->value == new->value)
		ft_error(IS_OVERLAPPED);
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
	new->prev = new;
	new->next = new;
	return(new);
}

