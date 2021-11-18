/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:34:57 by maemi             #+#    #+#             */
/*   Updated: 2021/11/18 15:14:55 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	if (start == end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &s1[start], end - start + 1);
	return (ret);
}
