/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:16:33 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/10 23:19:21 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(long long nbr, int isupper)
{
	static char	digit[16] = "0123456789abcdef";
	char		buf[20];
	int			i;

	i = -1;
	if (isupper)
		while (++i < 16)
			digit[i] = ft_toupper(digit[i]);
	i = 18;
	ft_bzero(buf, 20);
	while (nbr > 0)
	{
		buf[i--] = digit[nbr % 16];
		nbr /= 16;
	}
	write(1, buf + i, 19 - i);
	return (18 - i);
}
