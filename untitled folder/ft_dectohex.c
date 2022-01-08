/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:56:02 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 19:53:46 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(size_t dec)
{
	int	c;

	c = 1;
	while (dec > 15)
	{
		dec /= 16;
		c++;
	}
	return (c);
}

static size_t	pow_hex(int n)
{
	size_t	ret;

	ret = 1;
	while (n--)
		ret *= 16;
	return (ret);
}

char	*ft_dectohex(size_t dec, int is_int)
{
	char	*cp;
	int		len;
	int		i;
	size_t	tmp;

	i = 0;
	if (is_int)
		dec = (unsigned int) dec;
	len = hex_len(dec);
	cp = (char *) malloc(sizeof(char) * (len + 1));
	if (!cp)
		return (0);
	while (len > 0)
	{
		tmp = pow_hex(len - 1);
		cp[i++] = g_hex[dec / tmp];
		dec %= tmp;
		len--;
	}
	cp[i] = '\0';
	return (cp);
}
