/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/31 10:01:15 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst_and_content(void *input)
{
	t_split	*slist;
	t_list	*lst;

	lst = input;
	if (lst != NULL)
	{
		if (lst->content != NULL)
		{
			slist = lst->content;
			if (slist->ptr != NULL)
				free(slist->ptr);
		}
		free(lst);
	}
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
	t_list	*cur_lst;
	t_split	*slist;

	if (content == NULL)
	{
		ft_lstclear(&lst, &free);
		return (NULL);
	}
	if (content->len <= 0)
	{
		free(content);
		content = NULL;
	}
	ft_lstadd_back(&lst, ft_lstnew(content));
	cur_lst = lst;
	while (lst != NULL && cur_lst != NULL && cur_lst->content != NULL)
	{
		slist = cur_lst->content;
		slist->ptr = ft_substr(s, slist->start_index, slist->len);
		if (slist->ptr == NULL)
			ft_lstclear(&lst, &free_lst_and_content);
		cur_lst = cur_lst -> next;
	}
	return (lst);
}

static t_list	*generate_t_list(char const *s, char c)
{
	t_list	*lst;
	t_split	*con;
	size_t	cur_index;

	con = (t_split *)ft_calloc(1, sizeof(t_split));
	up_content(con, 0, -1);
	lst = NULL;
	if (con == NULL || s == NULL)
		return (NULL);
	while (con != NULL && s[con->start_index + (++(con->len))] != '\0')
	{
		cur_index = con->start_index + con->len;
		if (s[cur_index] == c && con->len > 0)
		{
			ft_lstadd_back(&lst, ft_lstnew(con));
			con = (t_split *)ft_calloc(1, sizeof(t_split));
			up_content(con, cur_index + 1, -1);
		}
		else if (s[cur_index] == c && con->len == 0)
			up_content(con, cur_index + 1, -1);
	}
	return (finalize_get_lst(lst, con, s));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**ans;
	t_list	*lst;
	t_list	*lst_init;

	if (s == NULL || *s == '\0')
		return ((char **)ft_calloc(1, sizeof(char *)));
	lst = generate_t_list(s, c);
	if (lst == NULL)
		return (NULL);
	ans = (char **)ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (ans == NULL)
		return (NULL);
	lst_init = lst;
	i = 0;
	while (lst != NULL && lst->content != NULL)
	{
		ans[i++] = ((t_split *)(lst->content))->ptr;
		lst = lst->next;
	}
	ft_lstclear(&lst_init, &free);
	return (ans);
}

/*
#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	print_and_free(char **a)
{
	int		i;

	i = 0;
	while (a[i] != NULL)
	{
		printf("%s\n",a[i]);
		free(a[i++]);
	}
	free(a);
}

int	main(void)
{
	char	**a;

	a = ft_split("hello world", ' ');
	assert(!strcmp(a[0], "hello"));
	assert(!strcmp(a[1], "world"));
	print_and_free(a);

	a = ft_split("abcdaba", 'a');
	assert(!strcmp(a[0], "bcd"));
	assert(!strcmp(a[1], "b"));
	print_and_free(a);

	a = ft_split("abcdaba", '\0');
	assert(!strcmp(a[0], "abcdaba"));
	print_and_free(a);

	a = ft_split("", 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split(NULL, 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split("      ", ' ');
	assert(*a == NULL);
	print_and_free(a);

	system("leaks a.out");
	return (0);
}
*/