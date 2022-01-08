/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:02 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:52:37 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(va_list *ap)
{
	const char	*cp;
	int			c;

	c = 0;
	cp = (const char *)va_arg(*ap, const char *);
	if (!cp)
		return (write(1, "(null)", 6));
	while (*cp)
	{
		write(1, cp++, 1);
		c++;
	}
	return (c);
}
