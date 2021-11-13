/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:31 by maemi             #+#    #+#             */
/*   Updated: 2021/11/13 19:37:05 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	indexd;
	size_t	indexs;
	size_t	ret;

	ret = 0;
	indexd = 0;
	while (dst[indexd])
	{
		if (ret < dstsize)
			ret++;
		indexd++;
	}
	indexs = 0;
	while (src[indexs++])
		ret++;
	indexs = 0;
	while (src[indexs] && indexd + indexs + 1 < dstsize)
	{
		dst[indexd + indexs] = src[indexs];
		indexs++;
	}
	dst[indexd + indexs] = 0;
	return (ret);
}
