/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:49 by maemi             #+#    #+#             */
/*   Updated: 2021/11/24 15:35:26 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	char		tc;

	tmp = NULL;
	tc = (char)c;
	if (*s == tc)
		tmp = s;
	while (*s++)
	{
		if (*s == tc)
			tmp = s;
	}
	return ((char *)tmp);
}
