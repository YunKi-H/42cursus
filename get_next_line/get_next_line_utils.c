/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:21:31 by yuhwang           #+#    #+#             */
/*   Updated: 2021/12/09 19:57:51 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	tc;

	tmp = (char *)s;
	tc = (char)c;
	if (*tmp == tc)
		return (tmp);
	while (*tmp++)
	{
		if (*tmp == tc)
			return (tmp);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*ret = '\0';
		return (ret);
	}
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
