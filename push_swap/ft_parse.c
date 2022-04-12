/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:25:57 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/12 11:16:59 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <limits.h>

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

void	ft_error(int err)
{
	write(2, "Error\n", 6);
	exit(err);
}

void	ft_parse(t_stack **a, int argc, char **argv)
{
	int			i;
	long long	k;
	char		**strs;

	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		while (*strs)
		{
			if (ft_isnum(*strs))
				k = ft_atol(*strs);
			else
				ft_error(IS_NOT_NUM);
			if (ft_isint(k))
				ft_stack_push(a, k);
			else
				ft_error(OUT_OF_INT);
			strs++;
		}
		free(strs);
	}
}
