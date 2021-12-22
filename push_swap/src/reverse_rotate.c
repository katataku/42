/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 09:58:12 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **lst)
{
	t_list	*tmp;
	int		i;
	t_list	*tar;

	tmp = ft_lstlast(*lst);
	tar = *lst;
	i = ftlstsize(lst);
	while (i-- > 2)
	{
		tar = tar->next;
	}
	tar->next = NULL;
	ft_lstadd_front((lst), tmp);
}

void	rra(t_stack *stack)
{
	ft_putstr_fd("rra\n", 1);
	rrotate(stack->lst_a);
}

void	rrb(t_stack *stack)
{
	ft_putstr_fd("rrb\n", 1);
	rrotate(stack->lst_b);
}

void	rrr(t_stack *stack)
{
	ft_putstr_fd("rrr\n", 1);
	rrotate(stack->lst_a);
	rrotate(stack->lst_b);
}

