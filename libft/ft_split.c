/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/29 12:03:06 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **ptr, t_list	*lst)
{
	int	i;
	int	len;

	len = sizeof(lst);
	i = -1;
	if (ptr != NULL)
	{
		while (++i < len)
		{
			if (ptr[i] != NULL)
				free(ptr[i]);
			else
				break ;
		}
		free(ptr);
	}
	ft_lstclear(&lst, &free);
	return (NULL);
}

static void	up_content(t_split *content, int start_index, int len)
{
	if (content != NULL)
	{
		content->start_index = start_index;
		content->len = len;
	}
}

static t_list	*finalize_get_lst(t_list *lst, t_split *content, char const *s)
{
	if (content == NULL || s == NULL)
	{
		ft_lstclear(&lst, &free);
		return (NULL);
	}
	if (content->len > 0)
		ft_lstadd_back(&lst, ft_lstnew(content));
	else
		free(content);
	return (lst);
}

static t_list	*get_lst(char const *s, char c)
{
	t_list	*lst;
	t_split	*con;
	int		tmp_ind;

	con = (t_split *)ft_calloc(1, sizeof(t_split));
	up_content(con, 0, -1);
	lst = NULL;
	if (con == NULL || s == NULL)
		return (NULL);
	while (con != NULL && s[con->start_index + (++con->len)] != '\0')
	{
		if (s[con->start_index + con->len] != c)
			continue ;
		if (con->len > 0)
		{
			ft_lstadd_back(&lst, ft_lstnew(con));
			con = (t_split *)ft_calloc(1, sizeof(t_split));
			tmp_ind = ((t_split *)(ft_lstlast(lst)->content))->start_index + 1;
			tmp_ind += ((t_split *)(ft_lstlast(lst)->content))->len;
			up_content(con, tmp_ind, -1);
		}
		else
			up_content(con, con->start_index + con->len + 1, -1);
	}
	return (finalize_get_lst(lst, con, s));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ans;
	t_list	*lst;
	t_split	*slist;

	if (s == NULL)
		return ((char **)ft_calloc(1, sizeof(char *)));
	lst = get_lst(s, c);
	if (lst == NULL)
		return ((char **)ft_calloc(1, sizeof(char *)));
	ans = (char **)ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (ans == NULL)
		return (ans);
	i = -1;
	while (lst != NULL)
	{
		slist = lst->content;
		ans[++i] = (char *)ft_calloc(slist->len + 1, sizeof(char));
		if (ans[i] == NULL)
			return (free_all(ans, lst));
		ft_strlcpy(ans[i], (char *)s + slist->start_index, slist->len + 1);
		lst = lst->next;
	}
	ft_lstclear(&lst, &free);
	return (ans);
}
