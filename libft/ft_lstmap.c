/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:56:47 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/12 14:40:20 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ans;
	t_list	*new_node;

	ans = (t_list **)ft_calloc(1, sizeof(t_list *));
	while (lst != NULL)
	{
		new_node = ft_lstnew(lst->content);
		if (new_node == NULL)
		{
			ft_lstclear(ans, del);
			return (NULL);
		}
		new_node->content = f(new_node->content);
		ft_lstadd_back(ans, new_node);
		lst = lst->next;
	}
	return (*ans);
}
