/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 09:21:56 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	(stack->lst_a) = (t_list **) malloc(sizeof(t_list *));
	(stack->lst_b) = (t_list **) malloc(sizeof(t_list *));
	if ((stack->lst_a) == NULL || (stack->lst_b) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (stack);
}

char	**init_arg_list(int argc, char **argv)
{
	char	**arg_list;
	int		i;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	arg_list = (char **)ft_calloc(sizeof(char *), argc);
	if (arg_list == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	i = 0;
	while (argv[++i] != NULL)
	{
		arg_list[i - 1] = ft_strdup(argv[i]);
		if (arg_list[i - 1] == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
	}
	return (arg_list);
}
