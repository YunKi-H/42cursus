/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemi <maemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:06:49 by maemi             #+#    #+#             */
/*   Updated: 2021/11/22 14:16:15 by maemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	tsize;

	tsize = count * size;
	if (count && size > (size_t)-1 / count)
		return (NULL);
	result = malloc(tsize);
	if (!result)
		return (NULL);
	ft_bzero(result, tsize);
	return (result);
}
