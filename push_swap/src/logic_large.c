/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 17:01:36 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_lower_tob(t_stack *stack, int *a_hight)
{
	int	i;
	int	key;

	i = *a_hight;
	key = get_top(*(stack->lst_a));
	while (i-- > 0)
	{
		if (getter(*(stack->lst_a), 0) <= key)
		{
			(*a_hight)--;
			pb(stack);
		}
		else
			ra(stack);
	}
	rra_n(stack, *a_hight);
}

void	sort_lower(t_stack *stack)
{
	int	tmp_a_hight;
	int	key;

	tmp_a_hight = 0;
	while (ft_lstsize(*(stack->lst_b)) > MINI_SIZE_LIMIT)
	{
		key = get_last(*(stack->lst_b));
		while (get_top(*(stack->lst_b)) != key)
		{
			if (get_top(*(stack->lst_b)) > key)
			{
				tmp_a_hight++;
				pa(stack);
				continue ;
			}
			if (get_top(*(stack->lst_b)) == get_min(*(stack->lst_b)))
				para(stack);
			else
				rb(stack);
		}
	}
	sort_mini_b(stack);
	push_swap(stack, tmp_a_hight);
}

void	push_swap(t_stack *stack, int a_hight)
{
	if (is_sorted(*(stack->lst_a)) && ft_lstsize(*(stack->lst_b)) == 0)
		return ;
	if (a_hight < MINI_SIZE_LIMIT)
	{
		pb_n(stack, a_hight);
		sort_mini_b(stack);
		return ;
	}
	send_lower_tob(stack, &a_hight);
	sort_lower(stack);
	push_swap(stack, a_hight);
}
