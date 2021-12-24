/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/24 15:50:05 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>
# include <assert.h>

typedef struct s_stack
{
	t_list	**lst_a;
	t_list	**lst_b;
	int		a_hight;
	int		b_hight;
}	t_stack;

t_stack	*init_stack(void);
char	**init_arg_list(int argc, char **argv);
void	push_swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
int		get_top(t_list *lst);
int		get_last(t_list *lst);
int		get_sec(t_list *lst);
int		get_third(t_list *lst);
int		get_min(t_list *lst);
void	ft_lstdel_lastone(t_list **lst, void (*del)(void*));
void	print_lst(t_list *lst);
void print_stack(t_stack *stack);
#endif
