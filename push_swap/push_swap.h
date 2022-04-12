/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:38:04 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/12 11:16:29 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OUT_OF_INT 1
# define IS_NOT_NUM 2
# define IS_DUPLICATED 3
# define MALLOC_FAILED 4

typedef struct s_stack
{
	struct s_stack	*prev;
	ssize_t			value;
	struct s_stack	*next;
}	t_stack;

void	ft_error(int err);

#endif
