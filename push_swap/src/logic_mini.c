/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 17:06:52 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mini_a3(t_stack *stack)
{
	t_list	**lst;

	lst = stack->lst_a;
	if (get_top(*lst) > get_sec(*lst) && get_sec(*lst) > get_third(*lst))
		sa(stack);
	if (get_top(*lst) < get_sec(*lst) && get_top(*lst) > get_third(*lst))
		rra(stack);
	if (get_top(*lst) > get_sec(*lst) && get_top(*lst) < get_third(*lst))
		sa(stack);
	if (get_top(*lst) < get_third(*lst) && get_sec(*lst) > get_third(*lst))
		sa(stack);
	if (get_top(*lst) > get_third(*lst) && get_sec(*lst) < get_third(*lst))
		ra(stack);
}

void	sort_mini_a(t_stack *stack)
{
	t_list	**lst;

	lst = stack->lst_a;
	if (is_sorted(*lst))
		return ;
	if (ft_lstsize(*lst) == 2)
		if (get_top(*lst) > get_sec(*lst))
			sa(stack);
	if (ft_lstsize(*lst) == 3)
		sort_mini_a3(stack);
	if (ft_lstsize(*lst) > 3)
	{
		while (get_top(*lst) != get_min(*lst))
		{
			if (find(*lst, get_min(*lst)) > ft_lstsize(*lst) / 2)
				rra(stack);
			else
				ra(stack);
		}
		pb(stack);
		sort_mini_a(stack);
		pa(stack);
	}
}

void	para(t_stack *stack)
{
	pa(stack);
	ra(stack);
}

void	sort_mini_b3(t_stack *stack)
{
	t_list	**lst;

	lst = stack->lst_b;
	if (get_top(*lst) > get_sec(*lst) && get_sec(*lst) > get_third(*lst))
		sb(stack);
	if (get_top(*lst) < get_sec(*lst) && get_top(*lst) > get_third(*lst))
		rrb(stack);
	if (get_top(*lst) > get_sec(*lst) && get_top(*lst) < get_third(*lst))
		sb(stack);
	if (get_top(*lst) < get_third(*lst) && get_sec(*lst) > get_third(*lst))
		sb(stack);
	if (get_top(*lst) > get_third(*lst) && get_sec(*lst) < get_third(*lst))
		rb(stack);
}

void	sort_mini_b(t_stack *stack)
{
	t_list	**lst;

	lst = stack->lst_b;
	while (ft_lstsize(*lst) > 3)
	{
		while (get_top(*lst) != get_min(*lst))
		{
			if (find(*lst, get_min(*lst)) > ft_lstsize(*lst) / 2)
				rrb(stack);
			else
				rb(stack);
		}
		para(stack);
	}
	if (ft_lstsize(*lst) == 2)
		if (get_top(*lst) > get_sec(*lst))
			sb(stack);
	if (ft_lstsize(*lst) == 3)
		sort_mini_b3(stack);
	while (ft_lstsize(*(stack->lst_b)) > 0)
		para(stack);
}
