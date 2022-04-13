/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:20:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/13 11:05:56 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	ft_parse(a, argc, argv);
	move_atob(a, b);
	move_btoa(a, b);
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
	if (*str == '+' || *str == '-' || ft_isdigit(*str))
		str++;
	else
		return (0);
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

void	ft_parse(t_stack **a, int argc, char **argv)
{
	int		i;
	size_t	value;
	char	**strs;

	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		while (*strs)
		{
			if (ft_isnum(*strs))
				value = ft_atol(*strs);
			else
				ft_error(IS_NOT_NUM);
			if (ft_isint(value))
				ft_stack_push(a, ft_node_new(value));
			else
				ft_error(IS_NOT_INT);
			strs++;
		}
		free(strs);
	}
}

t_node	*ft_new_node(ssize_t value)
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

void	ft_init_stack(t_stack *stack)
{

}
