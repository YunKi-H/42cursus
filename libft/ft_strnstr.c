/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:46 by maemi             #+#    #+#             */
/*   Updated: 2021/11/21 15:20:42 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*t1;
	char	*t2;
	size_t	i;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			t1 = (char *)&haystack[i];
			t2 = (char *)needle;
			while (*t1 && *t2 && *t1 == *t2 && t1 < haystack + len)
			{
				t1++;
				t2++;
			}
			if (*t2 == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
