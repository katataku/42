/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:56:47 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/27 17:50:55 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ans;
	t_list	*n_node;

	ans = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (ans == NULL)
		return (NULL);
	while (lst != NULL)
	{
		n_node = ft_lstnew(lst->content);
		if (n_node == NULL)
		{
			ft_lstclear(ans, del);
			return (NULL);
		}
		if (f != NULL)
			n_node->content = f(n_node->content);
		ft_lstadd_back(ans, n_node);
		lst = lst->next;
	}
	return (*ans);
}
