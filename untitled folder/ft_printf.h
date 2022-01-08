/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:47:55 by dha               #+#    #+#             */
/*   Updated: 2022/01/08 23:40:29 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define MAX_SPEC 9

typedef int			(*t_conv)(va_list *ap);

int		ft_printf(const char *format, ...);
int		print_c(va_list *ap);
int		print_s(va_list *ap);
int		print_p(va_list *ap);
int		print_i(va_list *ap);
int		print_u(va_list *ap);
int		print_x(va_list *ap);
int		print_ux(va_list *ap);

char	*ft_itoa(int n);
char	*ft_dectohex(size_t dec, int is_int);
int		ft_toupper(int c);

static const t_conv	g_funcs[MAX_SPEC] =
{
	print_c, print_s, print_p, print_i, print_i, print_u, print_x, print_ux
};

static const char	g_form_spec[MAX_SPEC] =
{
	'c', 's', 'p', 'i', 'd', 'u', 'x', 'X'
};

static const char	*g_hex = "0123456789abcdef";

#endif