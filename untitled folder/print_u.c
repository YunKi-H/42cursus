/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:03 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:41:14 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	alen(unsigned int n)
{
	unsigned long long	num;
	unsigned char		len;

	if (n == 0)
		return (1);
	len = 0;
	num = n;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static unsigned int	pow_ten(unsigned char exp)
{
	unsigned int	ret;

	ret = 1;
	while (exp--)
		ret *= 10;
	return (ret);
}

static char	*ft_utoa(unsigned int n)
{
	unsigned long long	num;
	char				*ret;
	unsigned char		len;
	unsigned char		i;

	len = alen(n);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	num = n;
	while (len > 0)
	{
		ret[i++] = (num / pow_ten(len - 1)) + '0';
		num %= pow_ten(len - 1);
		len--;
	}
	ret[i] = '\0';
	return (ret);
}

int	print_u(va_list *ap)
{
	char			*cp;
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = (unsigned int)va_arg(*ap, unsigned int);
	cp = ft_utoa(nbr);
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
