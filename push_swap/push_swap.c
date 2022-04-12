/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:20:09 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/11 13:48:23 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	ft_parse(a, argc, argv);
	move_atob(a, b);
	move_btoa(a, b);
	return (0);
}
