/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/06 14:43:53 by takkatao         ###   ########.fr       */
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
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("sa")));
	swap(stack->lst_a);
}

void	sb(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("sb")));
	swap(stack->lst_b);
}
