/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:16:33 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/11 01:30:53 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long nbr, int isdecimal, int isupper)
{
	static char	digit[16] = "0123456789abcdef";
	char		buf[20];
	int			i;
	int			flag;

	if (isdecimal)
		flag = 10;
	else
		flag = 16;
	if (!nbr)
		return (write(1, "0", 1));
	i = -1;
	if (isupper)
		while (++i < 16)
			digit[i] = ft_toupper(digit[i]);
	i = 18;
	ft_bzero(buf, 20);
	while (nbr > 0)
	{
		buf[i--] = digit[nbr % flag];
		nbr /= flag;
	}
	write(1, buf + i + 1, 18 - i);
	return (18 - i);
}
