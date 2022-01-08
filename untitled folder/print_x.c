/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:06 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:41:14 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(va_list *ap)
{
	char			*cp;
	unsigned int	dec;
	int				i;

	i = 0;
	dec = (unsigned int)va_arg(*ap, unsigned int);
	cp = ft_dectohex(dec, 1);
	if (!cp)
		return (-1);
	while (cp[i])
	{
		write(1, cp + i, 1);
		i++;
	}
	free(cp);
	return (i);
}
