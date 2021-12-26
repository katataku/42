/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 04:39:51 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	getter(t_list *lst, int i)
{
	if (i == 0)
	{
		return (ft_atoi(lst->content));
	}
	if (i > 0)
		return (getter(lst->next, i - 1));
	return (getter(lst, ft_lstsize(lst) + i));
}

int	find(t_list *lst, int i)
{
	if (lst == NULL)
		return (0);
	if (ft_atoi(lst->content) == i)
		return (0);
	return (1 + find(lst->next, i));
}

int	get_top(t_list *lst)
{
	assert(lst != NULL);
	return (getter(lst, 0));
}

int	get_last(t_list *lst)
{
	return (getter(lst, -1));
}

int	get_sec(t_list *lst)
{
	return (getter(lst, 1));
}

int	get_third(t_list *lst)
{
	return (getter(lst, 2));
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

int	get_max(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL)
	{
		if (max < ft_atoi(lst->content))
			max = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (max);
}



int	is_sorted(t_list *lst)
{
	int	cur;

	cur = INT_MIN;
	while (lst != NULL)
	{
		if (cur > ft_atoi(lst->content))
			return (0);
		cur = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (1);
}


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
//	ft_putchar_fd('\n', 1);
}

void print_stack(t_stack *stack)
{
	ft_putstr_fd("lst_a:", 1);
	print_lst_int(*(stack->lst_a));
	ft_putstr_fd("lst_b:", 1);
	print_lst_int(*(stack->lst_b));
	ft_putstr_fd("high_a:", 1);
	ft_putnbr_fd(stack->a_hight,1);
	ft_putstr_fd("\nhigh_b:", 1);
	ft_putnbr_fd(stack->b_hight,1);
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

void lst_ans_compose(t_list **lst)
{
	t_list	*tar = *lst;
	
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


int get_avg(t_list **lst)
{
	t_list	*tar = *lst;
	int		sum = 0;
	int		cnt = 0;
	
	while (tar != NULL)
	{
		if (ft_atoi(tar->content) == get_min(*lst))
			break ;
		sum += ft_atoi(tar->content);
		tar = tar->next;
		cnt++;
	}
	return (sum / cnt);
}

int	get_next(t_stack *stack)
{
	t_list *cur;
	int ans;
	t_list *tmp;
	int	min;

	cur = *(stack->lst_a);
	min = get_min(*(stack->lst_a));
	if (min > get_min(*(stack->lst_b)))
		min = get_min(*(stack->lst_b));
	while (cur != NULL && ft_atoi(cur->content) != min)
		cur = cur->next;
	while (cur != NULL)
	{
		if (cur->next == NULL || ft_atoi(cur->content) > ft_atoi(cur->next->content))
			break ;
		cur = cur->next;
	}
	tmp = *(stack->lst_b);
	ans = ft_atoi(tmp->content);
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > ft_atoi(cur->content) && ft_atoi(tmp->content) < ans)
			ans = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
	return (ans);
}
