/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/05 09:25:20 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_split	*generate_con_and_addback(t_list **lst, int start_ind, int len)
{
	t_split	*content;

	content = (t_split *)ft_calloc(1, sizeof(t_split));
	if (content == NULL)
	{
		ft_lstclear(lst, &free);
		return (NULL);
	}
	content->start_index = start_ind;
	content->len = len;
	ft_lstadd_back(lst, ft_lstnew(content));
	return (content);
}

static t_list	*generate_t_list(char const *s, char c)
{
	t_split	*con;
	t_list	*lst;
	size_t	start_index;
	size_t	len;

	lst = NULL;
	start_index = 0;
	len = -1;
	while (true)
	{
		if (s[start_index + ++len] != '\0' && s[start_index + (len)] != c)
			continue ;
		if (len > 0)
		{
			con = generate_con_and_addback(&lst, start_index, len);
			if (con == NULL)
				return (NULL);
		}
		if (s[start_index + (len)] == '\0')
			break ;
		start_index = start_index + len + 1;
		len = -1;
	}
	ft_lstadd_back(&lst, ft_lstnew(NULL));
	return (lst);
}

static char	**free_ans(char **ans)
{
	size_t	i;

	if (ans == NULL)
		return (NULL);
	i = 0;
	while (ans[i] != NULL)
	{
		free(ans[i]);
		i++;
	}
	free(ans);
	return (NULL);
}

static char	**generate_ans(t_list	*lst_init, char const *s)
{
	char	**ans;
	t_list	*cur_lst;
	t_split	*content;
	size_t	i;

	ans = (char **)ft_calloc(ft_lstsize(lst_init) + 1, sizeof(char *));
	if (ans == NULL)
		return (NULL);
	i = 0;
	cur_lst = lst_init;
	while (lst_init != NULL && cur_lst != NULL && cur_lst->content != NULL)
	{
		content = cur_lst->content;
		ans[i] = ft_substr(s, content->start_index, content->len);
		if (ans[i++] == NULL)
			return (free_ans(ans));
		cur_lst = cur_lst -> next;
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	t_list	*lst;

	if (s == NULL)
		return ((char **)ft_calloc(1, sizeof(char *)));
	lst = generate_t_list(s, c);
	if (lst == NULL)
		return (NULL);
	ans = generate_ans(lst, s);
	ft_lstclear(&lst, &free);
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

	if (a != NULL)
	{
		i = 0;
		while (a[i] != NULL)
		{
			printf("  %s\n",a[i]);
			free(a[i++]);
		}
	}
	free(a);
	printf("  ---free completed---\n");

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

	a = ft_split("\0aa\0bbb", '\0');
	assert(*a == NULL);
	print_and_free(a);

	system("leaks a.out");
	return (0);
}
*/