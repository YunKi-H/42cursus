/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:45 by maemi             #+#    #+#             */
/*   Updated: 2021/11/19 19:21:30 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdcount(char *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] == c)
		{
			while (s[index] == c && s[index])
				index++;
			count++;
		}
	}
	return (count);
}

static int	ft_wdlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && !(s[len] == c))
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wdcount;
	int		i;

	result = (char **)malloc(sizeof(char *) * (ft_wdcount(s, c) + 1));
	if (!result)
		return (NULL);
	wdcount = 0;
	while (*s)
	{
		i = 0;
		if (!(*s == c))
		{
			result[wdcount] = (char *)malloc(ft_wdlen(s, c) + 1);
			while (!(*(s + i) == c) && *(s + i))
			{
				result[wdcount][i] = (s + i);
				i++;
			}
			result[wdcount++][i] = 0;
		}
		s += i + 1;
	}
	result[wdcount] = 0;
	return (result);
}
