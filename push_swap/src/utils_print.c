/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 13:27:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst_int(t_list *lst)
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

void	print_lst_str(t_list *lst)
{
	while (lst != NULL)
	{
		assert(lst->content != NULL);
		ft_putstr_fd((lst->content), 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

void	print_stack(t_stack *stack)
{
	ft_putstr_fd("lst_a:", 1);
	print_lst_int(*(stack->lst_a));
	ft_putstr_fd("lst_b:", 1);
	print_lst_int(*(stack->lst_b));
	ft_putstr_fd("high_a:", 1);
	ft_putnbr_fd(stack->a_hight, 1);
	ft_putstr_fd("\nhigh_b:", 1);
	ft_putnbr_fd(stack->b_hight, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("lst_ans:", 1);
	print_lst_str(*(stack->lst_ans));
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

void	lst_ans_compose(t_list **lst)
{
	t_list	*tar;

	tar = *lst;
	while (tar != NULL && tar->next != NULL && tar->next->next != NULL)
	{
		if ((ft_strncmp(tar->next->content, "ra", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "rra", 3) == 0)
			|| (ft_strncmp(tar->next->content, "rra", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "ra", 3) == 0)
			|| (ft_strncmp(tar->next->content, "rb", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "rrb", 3) == 0)
			|| (ft_strncmp(tar->next->content, "rrb", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "rb", 3) == 0)
			|| (ft_strncmp(tar->next->content, "pa", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "pb", 3) == 0)
			|| (ft_strncmp(tar->next->content, "pb", 3) == 0 \
			&& ft_strncmp(tar->next->next->content, "pa", 3) == 0))
		{
			tar->next = tar->next->next->next;
			tar = *lst;
			continue ;
		}
		tar = tar->next;
	}
}
