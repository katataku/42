/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 05:32:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list	*tmp;

	ft_putstr_fd("ra\n", 1);
	tmp = *(stack->lst_a);
	*(stack->lst_a) = (*(stack->lst_a))->next;
	tmp->next = NULL;
	ft_lstadd_back((stack->lst_a), tmp);
}
