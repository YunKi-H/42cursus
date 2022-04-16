/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:38:04 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/16 19:30:35 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define IS_NOT_INT 1
# define IS_NOT_NUM 2
# define IS_OVERLAPPED 3
# define MALLOC_FAILED 4

# include <sys/types.h>

typedef struct s_node
{
	struct s_node	*prev;
	ssize_t			value;
	size_t			index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
}	t_stack;

void	ft_error(int err);
ssize_t	ft_atol(const char *str);
int		ft_isnum(char *str);
int		ft_isint(long long num);
void	ft_parse(t_stack *a, int argc, char **argv);
void	ft_stack_init(t_stack **stack);
void	ft_node_compare(t_node *exist, t_node *new);
void	ft_stack_push(t_stack *stack, t_node *new);
t_node	*ft_node_new(ssize_t value);
int		ft_issorted(t_stack *stack);
void	ft_atob(t_stack *a, t_stack *b);
void	ft_arg_case3(t_stack *stack);
void	ft_arg_case4(t_stack *stack);
void	ft_arg_case5(t_stack *stack);
size_t	ft_get_precision(size_t n);
void	ft_push(t_stack *from, t_stack *to);
void	ft_rotate(t_stack *stack);
void	ft_rev_rotate(t_stack *stack);
void	ft_btoa(t_stack *b, t_stack *a);

#endif
