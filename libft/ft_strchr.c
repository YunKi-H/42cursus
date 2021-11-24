/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:55 by yuhwang           #+#    #+#             */
/*   Updated: 2021/11/24 15:26:15 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
