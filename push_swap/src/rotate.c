/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/06 14:43:37 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = *(lst);
		*(lst) = (*(lst))->next;
		tmp->next = NULL;
		ft_lstadd_back((lst), tmp);
	}
}

void	ra(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("ra")));
	rotate(stack->lst_a);
}

void	rb(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("rb")));
	rotate(stack->lst_b);
}

void	rr(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, exit_error(ft_lstnew("rr")));
	rotate(stack->lst_a);
	rotate(stack->lst_b);
}
