/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/11 10:18:13 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median_rec(t_list *lst, int hight, int ans, int rec)
{
	int		tmp;
	t_list	*cur_lst;
	int		i;

	i = 0;
	tmp = INT_MAX;
	cur_lst = lst;
	if (rec == 0)
		return (ans);
	while (cur_lst != NULL && i++ < hight)
	{
		if (getter(cur_lst, 0) > ans && getter(cur_lst, 0) < tmp)
			tmp = getter(cur_lst, 0);
		cur_lst = cur_lst->next;
	}
	return (get_median_rec(lst, hight, tmp, rec - 1));
}

void	send_lower_tob(t_stack *stack, int *a_hight)
{
	int		i;
	int		key;

	i = *a_hight;
	key = get_median_rec(*(stack->lst_a), *a_hight, INT_MIN, *a_hight / 2);
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
	if (*a_hight != ft_lstsize(*(stack->lst_a)))
		rra_n(stack, *a_hight);
}

void	sort_lower_innerloop(t_stack *stack, int *tmp_a_hight, int key)
{
	if (getter(*(stack->lst_b), 1) == stack->s_lst[stack->s_cnt] && \
		getter(*(stack->lst_b), 0) == stack->s_lst[stack->s_cnt + 1])
		para_n(stack, 2);
	if (getter(*(stack->lst_b), -1) == stack->s_lst[stack->s_cnt])
		rrb(stack);
	if (getter(*(stack->lst_b), 0) == stack->s_lst[stack->s_cnt])
		para_n(stack, 1);
	if (getter(*(stack->lst_b), 0) > key)
	{
		(*tmp_a_hight)++;
		pa(stack);
	}
	else
		rb(stack);
}

void	sort_lower(t_stack *stack)
{
	int	tmp_a_hight;
	int	key;
	int	b_size;

	tmp_a_hight = 0;
	while (ft_lstsize(*(stack->lst_b)) > MINI_SIZE_LIMIT)
	{
		b_size = ft_lstsize(*(stack->lst_b));
		key = get_median_rec(*(stack->lst_b), b_size, INT_MIN, b_size / 2);
		while (get_max(*(stack->lst_b)) > key)
			sort_lower_innerloop(stack, &tmp_a_hight, key);
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
