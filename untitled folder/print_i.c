/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:00:56 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:41:14 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i(va_list *ap)
{
	char	*cp;
	int		nbr;
	int		i;

	i = 0;
	nbr = (int)va_arg(*ap, int);
	cp = ft_itoa(nbr);
	if (cp == 0)
		return (-1);
	while (cp[i])
	{
		write(1, cp + i, 1);
		i++;
	}
	free(cp);
	return (i);
}
