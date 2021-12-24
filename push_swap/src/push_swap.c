/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/24 14:22:55 by takkatao         ###   ########.fr       */
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

void	sort_mini(t_stack *stack)
{
	if (ft_lstsize(*(stack->lst_b)) == 2)
	{
		if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)))
			sb(stack);
	}
	if (ft_lstsize(*(stack->lst_b)) == 3)
	{
		if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)) \
			&& get_sec(*(stack->lst_b)) > get_third(*(stack->lst_b)))
			sb(stack);
		if (get_top(*(stack->lst_b)) < get_sec(*(stack->lst_b)) \
			&& get_top(*(stack->lst_b)) > get_third(*(stack->lst_b)))
			rrb(stack);
		if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)) \
			&& get_top(*(stack->lst_b)) < get_third(*(stack->lst_b)))
			sb(stack);
		if (get_top(*(stack->lst_b)) < get_third(*(stack->lst_b)) \
			&& get_sec(*(stack->lst_b)) > get_third(*(stack->lst_b)))
			sb(stack);
		if (get_top(*(stack->lst_b)) > get_third(*(stack->lst_b)) \
			&& get_sec(*(stack->lst_b)) < get_third(*(stack->lst_b)))
			rb(stack);
	}

}

void	size_mini(t_stack *stack)
{

	sort_mini(stack);
	while (ft_lstsize(*(stack->lst_b)) > 0)
	{
		pa(stack);
		ra(stack);
		// ft_lstdel_lastone(stack->lst_a, free);
	}
}

void	push_swap(t_stack *stack)
{
	int	low_num;
	int	high_num;
	int	i;
	int	tmp;

	low_num = 0;
	high_num = 0;
	i = stack->a_hight;
	//少ない時はsize_mini
	if (i < 4)
	{
		while (i-- > 0)
			pb(stack);
		size_mini(stack);
		return ;
	}
	//多い時
	//highとlowに分割。lowはbに。
	int key = get_top(*(stack->lst_a));
	while (i-- > 0)
	{
		if (get_top(*(stack->lst_a)) < key)
		{
			low_num++;
			pb(stack);
		}
		else
		{
			high_num++;
			ra(stack);
		}
	}
	//highはaのtopに戻す
	i = high_num;
	while (i-- > 0)
		rra(stack);
	//lowの対応
	i = low_num;
	tmp = stack->a_hight;
	if (i > 3)
	{
		//lowをaのtopに戻す
		while (i-- > 0)
		{
			pa(stack);
		}
		stack->a_hight = low_num;
		push_swap(stack);
	}
	else
	{
		size_mini(stack);
	}
	stack->a_hight = tmp - low_num - 1;
	ra(stack);
	if (stack->a_hight > 0)
		push_swap(stack);
}
