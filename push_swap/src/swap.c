/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 10:12:55 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	void	*tmp;

	if (*(lst) == NULL || (*(lst))->next == NULL)
		return ;
	tmp = (*(lst))->content;
	(*(lst))->content = ((*(lst))->next)->content;
	((*(lst))->next)->content = tmp;
}

void	sa(t_stack *stack)
{
	ft_putstr_fd("sa\n", 1);
	swap(stack->lst_a);
}

void	sb(t_stack *stack)
{
	ft_putstr_fd("sb\n", 1);
	swap(stack->lst_b);
}