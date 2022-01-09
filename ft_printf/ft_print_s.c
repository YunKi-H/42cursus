/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:32:31 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/09 23:32:57 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list *ap)
{
	const char	*str;
	int			len;

	str = (const char *)va_arg(*ap, const char *);
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}
