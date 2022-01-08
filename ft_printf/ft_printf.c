/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:37:54 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/08 14:52:44 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typecheck(char c, va_list *ap)
{
	int		len;
	char	*tmp;

	if (c == 'c')
	{
		write(1, va_arg(*ap, int), 1);
		len = 1;
	}
	else if (c == 's')
	{
		len = ft_strlen(*ap);
		write(1, *ap, len);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_typecheck(*format, ap);
		}
		else
		{
			write(1, format, 1);
			len++;
			format++;
		}
	}
	return (len);
}
