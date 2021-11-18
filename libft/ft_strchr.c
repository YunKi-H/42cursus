/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:51:55 by yuhwang           #+#    #+#             */
/*   Updated: 2021/11/18 15:08:10 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	if (*tmp == c)
		return (tmp);
	while (*tmp++)
	{
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}
