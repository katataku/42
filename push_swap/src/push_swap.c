/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 05:05:19 by takkatao         ###   ########.fr       */
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
	int	key;

	low_num = 0;
	high_num = 0;
	i = stack->a_hight;
	if (is_sorted(*(stack->lst_a)) && ft_lstsize(*(stack->lst_b)) == 0)
		return ;
	//少ない時はsize_mini
	if (i < MINI_SIZE_LIMIT)
	{
		while (i-- > 0)
			pb(stack);
		size_mini(stack);
		return ;
	}
	//多い時
	//highとlowに分割。lowはbに。
	key = get_top(*(stack->lst_a));
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
	if (i > MINI_SIZE_LIMIT)
	{
		//lowをaのtopに戻す
		stack->a_hight = 0;
		while (ft_lstsize(*(stack->lst_b)) > MINI_SIZE_LIMIT)
		{
			key = get_last(*(stack->lst_b));
			while (get_top(*(stack->lst_b)) != key)
			{
				if (get_top(*(stack->lst_b)) > key)
				{
					stack->a_hight++;
					pa(stack);
				}
				else
				{
					rb(stack);
				}
			}
		}
		sort_mini_b(stack);
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
