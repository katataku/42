/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 11:32:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_top(t_list *lst)
{
	return (ft_atoi(lst->content));
}

int	get_last(t_list *lst)
{
	return (ft_atoi((ft_lstlast(lst))->content));
}

int	get_sec(t_list *lst)
{
	return (ft_atoi((lst->next)->content));
}

void	push_swap(t_stack *stack)
{
	while (ft_lstsize(*(stack->lst_a)) > 0)
	{
		pb(stack);
		if (ft_lstsize(*(stack->lst_b)) > 1)
		{
			if (get_top(*(stack->lst_b)) > get_sec(*(stack->lst_b)))
				rb(stack);
			else
				sb(stack);
		}
	}
	rb(stack);
	while (ft_lstsize(*(stack->lst_b)) > 0)
	{
		pa(stack);
		while (get_top(*(stack->lst_a)) < get_last(*(stack->lst_a)))
		{
			rra(stack);
			pb(stack);
			if (get_top(*(stack->lst_b)) > get_last(*(stack->lst_b)))
				rrb(stack);
		}
		ra(stack);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	char	**arg_list;

	stack = init_stack();
	arg_list = init_arg_list(argc, argv);
	if (stack == NULL || arg_list == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	i = -1;
	while (arg_list[++i] != NULL)
		ft_lstadd_back((stack->lst_a), ft_lstnew(arg_list[i]));
	push_swap(stack);
	return (0);
}
