/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:48:57 by yuhwang           #+#    #+#             */
/*   Updated: 2021/11/16 16:57:56 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char)(s1 + i) != *(unsigned char)(s2 + i))
			return (*(unsigned char)(s1 + i) - *(unsigned char)(s2 + i));
		i++;
	}
	return (0);
}
