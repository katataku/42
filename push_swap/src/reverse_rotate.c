/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/24 17:37:02 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **lst)
{
	t_list	*tmp;
	int		i;
	t_list	*tar;

	i = ft_lstsize(*lst);
	if (i > 1)
	{
		tmp = ft_lstlast(*lst);
		tar = *lst;
		while (i-- > 2)
		{
			tar = tar->next;
		}
		tar->next = NULL;
		ft_lstadd_front((lst), tmp);
	}
}

void	rra(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, ft_lstnew("rra"));
	rrotate(stack->lst_a);
}

void	rrb(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, ft_lstnew("rrb"));
	rrotate(stack->lst_b);
}

void	rrr(t_stack *stack)
{
	ft_lstadd_back(stack->lst_ans, ft_lstnew("rrr"));
	rrotate(stack->lst_a);
	rrotate(stack->lst_b);
}
