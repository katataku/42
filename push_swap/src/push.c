/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/06 14:42:47 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dst)
{
	t_list	*tmp;

	tmp = *(lst_src);
	*(lst_src) = (*(lst_src))->next;
	tmp->next = NULL;
	ft_lstadd_front((lst_dst), tmp);
}

void	pa(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("pa")));
	push(stack->lst_b, stack->lst_a);
}

void	pb(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("pb")));
	push(stack->lst_a, stack->lst_b);
}

void	pb_n(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		pb(stack);
	}
}
