/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:28:37 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/17 18:34:26 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <limits.h>

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
		if (!*strs)
			ft_error(IS_NOT_NUM);
		while (strs[j])
		{
			if (!ft_isnum(strs[j]))
				ft_error(IS_NOT_NUM);
			value = ft_atol(strs[j]);
			if (!ft_isint(value))
				ft_error(IS_NOT_INT);
			ft_stack_push(a, ft_node_new(value));
			free(strs[j]);
			j++;
		}
		free(strs);
	}
}
