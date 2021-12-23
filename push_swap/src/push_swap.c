/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/23 09:28:16 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gnome_sort(t_stack *stack)
{
	int	init_lst_b_size;

	init_lst_b_size = ft_lstsize(*(stack->lst_b));
	while (ft_lstsize(*(stack->lst_a)) > 0)
	{
		pb(stack);
		if (ft_lstsize(*(stack->lst_b)) > 1 + init_lst_b_size)
		{
			if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)))
				rb(stack);
			else
				sb(stack);
		}
	}
	rb(stack);
	while (ft_lstsize(*(stack->lst_b)) > init_lst_b_size)
	{
		pa(stack);
		while (get_top(*(stack->lst_a)) < get_last(*(stack->lst_a)))
		{
			rra(stack);
			pb(stack);
		}
		ra(stack);
	}
	ft_lstclear(stack->lst_a, free);
	stack->lst_a = (t_list**)ft_calloc(1, sizeof(t_list*));
}


void	push_swap(t_stack *stack)
{
	int	low_num;
	int	init_lst_b_size;

	low_num = 0;
	init_lst_b_size = ft_lstsize(*(stack->lst_b));
	if (ft_lstsize(*(stack->lst_a)) < 400)
	{
		return (gnome_sort(stack));
	}
	while (ft_lstsize(*(stack->lst_a)) > 0)
	{
		pb(stack);
		if (ft_lstsize(*(stack->lst_b)) - init_lst_b_size > 1)
		{
			if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)))
				rb(stack);
			else
			{
				low_num++;
				sb(stack);
			}
		}
	}
	rb(stack);
	while (low_num-- > 0)
		pa(stack);
	push_swap(stack);
	rrb(stack);
	pa(stack);
	ra(stack);
	while (ft_lstsize(*(stack->lst_b)) > init_lst_b_size)
	{
		rrb(stack);
		pa(stack);
	}	
	push_swap(stack);
}
