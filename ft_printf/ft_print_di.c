/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:50:07 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/09 23:50:09 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(va_list *ap)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*ap, int));
	if (!str)
		return (INT_MIN);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
