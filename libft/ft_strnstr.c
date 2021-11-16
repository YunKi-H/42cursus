/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:46 by maemi             #+#    #+#             */
/*   Updated: 2021/11/16 19:19:19 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*thaystack;
	char	*tneedle;
	size_t	i;

	if (*needle == 0)
		return (haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			thaystack = haystack + 1;
			tneedle = needle + 1;
			while (*thaystack && *tneedle && *thaystack == *tneedle)
			{
				thaystack++;
				tneedle++;
			}
			if (*tneedle == 0)
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
