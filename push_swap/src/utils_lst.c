/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/24 15:49:52 by takkatao         ###   ########.fr       */
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

int	get_third(t_list *lst)
{
	return (ft_atoi((lst->next)->next->content));
}

int	get_min(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > ft_atoi(lst->content))
			min = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (min);
}


void	print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		assert(lst->content != NULL);
		ft_putnbr_fd(ft_atoi(lst->content), 1);
		ft_putstr_fd(" ", 1);
		lst = lst->next;
	}
	ft_putchar_fd('\n', 1);
}

void print_stack(t_stack *stack)
{
	ft_putstr_fd("lst_a:", 1);
	print_lst(*(stack->lst_a));
	ft_putstr_fd("lst_b:", 1);
	print_lst(*(stack->lst_b));
	ft_putstr_fd("high_a:", 1);
	ft_putnbr_fd(stack->a_hight,1);
	ft_putstr_fd("\nhigh_b:", 1);
	ft_putnbr_fd(stack->b_hight,1);
	ft_putstr_fd("\n", 1);
	

}

void	ft_lstdel_lastone(t_list **lst, void (*del)(void*))
{
	t_list	*pre;

	pre = NULL;
	if (*lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			pre = *lst;
			*lst = (*lst)->next;
		}
		if (pre != NULL)
			pre->next = NULL;
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
