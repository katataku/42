/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/23 09:22:51 by takkatao         ###   ########.fr       */
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
