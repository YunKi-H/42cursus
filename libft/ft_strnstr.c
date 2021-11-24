/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:46 by maemi             #+#    #+#             */
/*   Updated: 2021/11/24 17:11:16 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	slen;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	slen = ft_strlen(needle);
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			if (!ft_strncmp(&haystack[i], needle, slen) && i + slen <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
