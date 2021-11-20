/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:45 by maemi             #+#    #+#             */
/*   Updated: 2021/11/20 14:16:58 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freearr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i]);
	return (NULL);
}

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
	int		wdlen;

	result = (char **)malloc(sizeof(char *) * (ft_wdcount(s, c) + 1));
	if (!result)
		return (NULL);
	wdcount = 0;
	while (*s)
	{
		if (*s != c)
		{
			wdlen = ft_wdlen(s, c);
			result[wdcount] = (char *)malloc(wdlen + 1);
			if (!result[wdcount])
				return (ft_freearr(result, wdcount));
			ft_strlcpy(result[wdcount], s, wdlen + 1);
		}
		s += wdlen + 1;
	}
	result[wdcount] = 0;
	return (result);
}
