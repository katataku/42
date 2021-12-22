/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 05:31:29 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*tmp;

	ft_putstr_fd("pa\n", 1);
	tmp = *(stack->lst_b);
	*(stack->lst_b) = (*(stack->lst_b))->next;
	tmp->next = NULL;
	ft_lstadd_front((stack->lst_a), tmp);
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	ft_putstr_fd("pb\n", 1);
	tmp = *(stack->lst_a);
	*(stack->lst_a) = (*(stack->lst_a))->next;
	tmp->next = NULL;
	ft_lstadd_front((stack->lst_b), tmp);
}
