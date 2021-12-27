/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 13:28:39 by takkatao         ###   ########.fr       */
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
	(stack->lst_ans) = (t_list **) malloc(sizeof(t_list *));
	stack->str_pa = "pa\n";
	if ((stack->lst_a) == NULL \
		|| (stack->lst_b) == NULL || (stack->lst_ans) == NULL)
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

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	char	**arg_list;

	stack = init_stack();
	arg_list = init_arg_list(argc, argv);
	if (stack == NULL || arg_list == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	i = -1;
	while (arg_list[++i] != NULL)
		ft_lstadd_back((stack->lst_a), ft_lstnew(arg_list[i]));
	stack->a_hight = ft_lstsize(*stack->lst_a);
	stack->b_hight = ft_lstsize(*stack->lst_b);
	if (stack->a_hight < MINI_SIZE_LIMIT)
		sort_mini_a(stack);
	else
		push_swap(stack);
	lst_ans_compose((stack->lst_ans));
	print_lst_str(*(stack->lst_ans));
	return (0);
}
