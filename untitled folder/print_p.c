/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:00 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:53:16 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list *ap)
{
	char	*cp;
	size_t	dec;
	int		i;

	i = 0;
	dec = (size_t)va_arg(*ap, void *);
	cp = ft_dectohex(dec, 0);
	if (!cp)
		return (-1);
	write(1, "0x", 2);
	while (cp[i])
	{
		write(1, cp + i, 1);
		i++;
	}
	free(cp);
	return (i + 2);
}
