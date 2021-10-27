/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taku <taku@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:56:47 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/27 13:45:45 by taku             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ans;
	t_list	*n_node;

	ans = (t_list **)ft_calloc(1, sizeof(t_list *));
	while (lst != NULL)
	{
		n_node = ft_lstnew(lst->content);
		if (n_node == NULL)
		{
			ft_lstclear(ans, del);
			return (NULL);
		}
		n_node->content = f(n_node->content);
		ft_lstadd_back(ans, n_node);
		lst = lst->next;
	}
	return (*ans);
}
