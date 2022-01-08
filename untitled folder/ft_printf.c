/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:48:11 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fs_operator(const char **fs, va_list *ap)
{
	int	i;

	i = 0;
	if (**fs == '%')
		return (write(1, *fs, 1));
	while (g_form_spec[i] != **fs && g_form_spec[i])
		i++;
	if (!g_form_spec[i])
		return (0);
	i = g_funcs[i](ap);
	if (i < 0)
		return (-2147483648);
	else
		return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format != '\0' && ret >= 0)
	{
		if (*format == '%')
		{
			format++;
			ret += fs_operator(&format, &ap);
			if (ret < 0)
				return (-1);
		}
		else
		{
			ret += write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (ret);
}
