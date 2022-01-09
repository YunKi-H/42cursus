/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:33:24 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/09 23:04:38 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list *ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}
