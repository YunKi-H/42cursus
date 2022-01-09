/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:37:54 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/10 03:30:41 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_typecheck(char c, va_list *ap)
{
	int		len;
	char	*tmp;

	if (c == 'c')
		len = ft_print_c(ap);
	else if (c == 's')
		len = ft_print_s(ap);
	else if (c == 'p')
		;
	else if (c == 'd' || c == 'i')
		len = ft_print_di(ap);
	else if (c == 'u')
		;
	else if (c == 'x')
		;
	else if (c == 'X')
		;
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format && len >= 0)
	{
		if (*format == '%')
		{
			format++;
			len += ft_typecheck(*format++, &ap);
		}
		else
			len += write(1, format++, 1);
	}
	va_end(ap);
	return (len);
}
