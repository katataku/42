/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/11 13:12:29 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>
# include <assert.h>
# define MINI_SIZE_LIMIT 25

typedef struct s_stack
{
	t_list	**lst_a;
	t_list	**lst_b;
	t_list	**lst_ans;
	int		*s_lst;
	int		s_cnt;
}	t_stack;

t_stack	*init_stack(void);
char	**init_arg_list(int argc, char **argv);
void	push_swap(t_stack *stack, int a_hight);
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
int		get_max(t_list *lst);
void	ft_lstdel_lastone(t_list **lst, void (*del)(void*));
void	print_lst_int(t_list *lst);
void	print_lst_str(t_list *lst);
void	print_stack(t_stack *stack);
void	lst_ans_compose(t_list **lst);
void	sort_mini_a(t_stack *stack);
void	para_n(t_stack *stack, int n);
void	sort_mini_b(t_stack *stack);
int		is_sorted(t_list *lst);
int		get_avg(t_list **lst);
int		find(t_list *lst, int i);
int		getter(t_list *lst, int i);
void	pb_n(t_stack *stack, int n);
void	rra_n(t_stack *stack, int n);
char	**validate_arg_list(char **argv);
void	*exit_error(void *ptr);
int		handle_next_on_top(t_stack *stack);
#endif
