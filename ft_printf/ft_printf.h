/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 01:40:25 by yuhwang           #+#    #+#             */
/*   Updated: 2022/01/10 23:52:36 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_c(va_list *ap);
int	ft_print_s(va_list *ap);
int	ft_print_hex(long long nbr, int isupper);
int	ft_print_di(va_list *ap);

#endif
