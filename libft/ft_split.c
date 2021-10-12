/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/12 16:23:03 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **ptr, t_list	*lst)
{
	int	i;
	int	len;

	len = sizeof(lst);
	i = -1;
	while (++i < len)
	{
		if (ptr[i] != NULL)
			free(ptr[i]);
		else
			break ;
	}
	free(ptr);
	ft_lstclear(&lst, free);
	return (NULL);
}

static t_list	*get_lst(char const *s, char c)
{
	t_list			*ans;
	t_split_list	*content;
	int				index;

	content = (t_split_list *)ft_calloc(1, sizeof(t_split_list));
	if (content == NULL)
		return (NULL);
	ans = NULL;
	index = -1;
	while (s[++index] != '\0')
	{
		if (s[index] == c)
		{
			if (content->len > 0)
			{
				ft_lstadd_back(&ans, ft_lstnew(content));
				content = (t_split_list *)ft_calloc(1, sizeof(t_split_list));
				if (content == NULL)
				{
					ft_lstclear(&ans, free);
					return (NULL);
				}
			}
			content->start_index = index + 1;
			content->len = -1;
		}
		content->len++;
	}
	if (content->len > 0)
		ft_lstadd_back(&ans, ft_lstnew(content));
	else
		free(content);
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	char			**ans;
	t_list			*lst;
	t_split_list	*slist;

	if (s == NULL)
		return (NULL);
	lst = get_lst(s, c);
	ans = (char **)malloc(sizeof(char *) * ft_lstsize(lst));
	if (ans == NULL || s == NULL)
		return (NULL);
	i = -1;
	while (lst != NULL)
	{
		slist = lst->content;
		ans[++i] = (char *)ft_calloc(slist->len + 1, sizeof(char));
		ft_memmove(ans[i], (char *)s + slist->start_index, slist->len);
		if (ans[i] == NULL)
			return (free_all(ans, lst));
		lst = lst->next;
	}		
	ft_lstclear(&lst, free);
	return (ans);
}
