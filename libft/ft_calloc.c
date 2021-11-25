/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:06:49 by maemi             #+#    #+#             */
/*   Updated: 2021/11/25 13:56:13 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	tsize;

	if (count && size > (size_t)(-1) / count)
		return (NULL);
	tsize = count * size;
	result = malloc(tsize);
	if (!result)
		return (NULL);
	ft_bzero(result, tsize);
	return (result);
}
