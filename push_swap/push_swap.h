/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:38:04 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/13 10:50:17 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define IS_NOT_INT 1
# define IS_NOT_NUM 2
# define IS_DUPLICATED 3
# define MALLOC_FAILED 4

# include <sys/types.h>

typedef struct s_node
{
	struct s_node	*prev;
	ssize_t			value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
}	t_stack;

void	ft_error(int err);
int		ft_isnum(char *str);
int		ft_isint(long long num);
void	ft_parse(t_stack **a, int argc, char **argv);

#endif
