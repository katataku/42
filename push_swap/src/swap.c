/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 05:33:14 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	void	*tmp;

	ft_putstr_fd("sa\n", 1);
	if (*(stack->lst_a) == NULL || (*(stack->lst_a))->next == NULL)
		return ;
	tmp = (*(stack->lst_a))->content;
	(*(stack->lst_a))->content = ((*(stack->lst_a))->next)->content;
	((*(stack->lst_a))->next)->content = tmp;
}
