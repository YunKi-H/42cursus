/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:06:49 by maemi             #+#    #+#             */
/*   Updated: 2021/11/16 20:37:38 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	tsize;

	tsize = count * size;
	if (count && size != tsize / count)
		return (NULL);
	result = malloc(tsize);
	if (!result)
		return (NULL);
	ft_bzero(result, tsize);
	return (result);
}
