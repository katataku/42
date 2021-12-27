/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 16:16:26 by takkatao         ###   ########.fr       */
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
	{
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
		pa(stack);
		if (get_top(*lst) != get_min(*lst))
			rr(stack);
		else
			ra(stack);
	}
	if (ft_lstsize(*lst) == 2)
		if (get_top(*lst) > get_sec(*lst))
			sb(stack);
	if (ft_lstsize(*lst) == 3)
	{
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
	while (ft_lstsize(*(stack->lst_b)) > 0)
	{
		pa(stack);
		ra(stack);
		stack->sorted_len++;
	}
}

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
			{
				pa(stack);
				ra(stack);
				continue ;
			}
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
