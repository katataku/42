/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/25 09:06:15 by takkatao         ###   ########.fr       */
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
	if (is_sorted(*(stack->lst_a)))
		return ;
	if (ft_lstsize(*(stack->lst_a)) == 2)
	{
		if (get_top(*(stack->lst_a)) > get_sec(*(stack->lst_a)))
			sa(stack);
	}
	if (ft_lstsize(*(stack->lst_a)) == 3)
	{
		if (get_top(*(stack->lst_a)) > get_sec(*(stack->lst_a)) \
			&& get_sec(*(stack->lst_a)) > get_third(*(stack->lst_a)))
			sa(stack);
		if (get_top(*(stack->lst_a)) < get_sec(*(stack->lst_a)) \
			&& get_top(*(stack->lst_a)) > get_third(*(stack->lst_a)))
			rra(stack);
		if (get_top(*(stack->lst_a)) > get_sec(*(stack->lst_a)) \
			&& get_top(*(stack->lst_a)) < get_third(*(stack->lst_a)))
			sa(stack);
		if (get_top(*(stack->lst_a)) < get_third(*(stack->lst_a)) \
			&& get_sec(*(stack->lst_a)) > get_third(*(stack->lst_a)))
			sa(stack);
		if (get_top(*(stack->lst_a)) > get_third(*(stack->lst_a)) \
			&& get_sec(*(stack->lst_a)) < get_third(*(stack->lst_a)))
			ra(stack);
	}
	if (ft_lstsize(*(stack->lst_a)) > 3)
	{
		while (get_top(*(stack->lst_a)) != get_min(*(stack->lst_a)))
		{
			if (get_last(*(stack->lst_a)) == get_min(*(stack->lst_a)))
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
	while (ft_lstsize(*(stack->lst_b)) > 3)
	{
		while (get_top(*(stack->lst_b)) != get_min(*(stack->lst_b)))
		{
			if (get_top(*(stack->lst_b)) < get_sec(*(stack->lst_b)))
			{
				sb(stack);
				rb(stack);
			}
			rb(stack);
		}
		pa(stack);
		if (get_top(*(stack->lst_b)) != get_min(*(stack->lst_b)))
		{
			if (get_top(*(stack->lst_b)) < get_sec(*(stack->lst_b)))
				sb(stack);
			rr(stack);
		}
		else
			ra(stack);
	}
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
	sort_mini_b(stack);
	while (ft_lstsize(*(stack->lst_b)) > 0)
	{
		pa(stack);
		ra(stack);
	}
}

void	push_swap(t_stack *stack)
{
	int	low_num;
	int	high_num;
	int	i;
	int	tmp;
	int	mini_size_limit;

	mini_size_limit = 10;
	low_num = 0;
	high_num = 0;
	i = stack->a_hight;
	//少ない時はsize_mini
	if (is_sorted(*(stack->lst_a)) && ft_lstsize(*(stack->lst_b)) == 0)
		return ;
	if (i < mini_size_limit)
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
		tmp = i;
		t_list	*tmp_lst = *(stack->lst_a);
		while (tmp-- > 0)
		{
			if (ft_atoi(tmp_lst->content) >= key)
				tmp_lst = tmp_lst->next;
			else
				break ;
			if (tmp_lst == NULL)
				i = 0;
		}
		if (get_top(*(stack->lst_a)) < key)
		{
			low_num++;
			pb(stack);
		}
		else
		{
			high_num++;
			if (tmp > 1 && get_top(*(stack->lst_a)) > get_sec(*(stack->lst_a)) && get_sec(*(stack->lst_a)) > key)
				sa(stack);
			ra(stack);
		}
	}
	//highはaのtopに戻す
	if (low_num + high_num != ft_lstsize(*(stack->lst_a)) + ft_lstsize(*(stack->lst_b)))
	{
		i = high_num;
		while (i-- > 0)
			rra(stack);
	}
	//lowの対応
	i = low_num;
	tmp = stack->a_hight;
	if (i > mini_size_limit)
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
