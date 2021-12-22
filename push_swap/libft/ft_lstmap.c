/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:56:47 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/01 10:24:33 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*n_node;

	ans = NULL;
	while (lst != NULL)
	{
		n_node = ft_lstnew(lst->content);
		if (n_node == NULL)
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		if (f != NULL)
			n_node->content = f(n_node->content);
		ft_lstadd_back(&ans, n_node);
		lst = lst->next;
	}
	return (ans);
}

/*
#include <stdio.h>
int main()
{
    t_list *lst = ft_lstnew(ft_strdup("hello"));
    t_list *res = ft_lstmap(lst, NULL, NULL);
    printf("%s \n", res->content);
    system("leaks a.out");
}
*/