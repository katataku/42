/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 09:45:49 by takkatao         ###   ########.fr       */
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
	ft_putstr_fd("pa\n", 1);
	push(stack->lst_b, stack->lst_a);
}

void	pb(t_stack *stack)
{
	ft_putstr_fd("pb\n", 1);
	push(stack->lst_a, stack->lst_b);
}
