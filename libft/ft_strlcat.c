/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:31 by yuhwang           #+#    #+#             */
/*   Updated: 2021/11/26 12:44:30 by yuhwang          ###   ########.fr       */
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
