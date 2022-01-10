/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/10 18:41:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*exit_error(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (ptr);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)exit_error(malloc(sizeof(t_stack)));
	(stack->lst_a) = (t_list **)exit_error(ft_calloc(sizeof(t_list *), 1));
	(stack->lst_b) = (t_list **)exit_error(ft_calloc(sizeof(t_list *), 1));
	(stack->lst_ans) = (t_list **)exit_error(ft_calloc(sizeof(t_list *), 1));
	return (stack);
}

char	**init_arg_list(int argc, char **argv)
{
	char	**arg_list;
	int		i;

	if (argc < 2)
		return ((char **)exit_error(ft_calloc(sizeof(char *), 1)));
	if (argc == 2)
		return (exit_error(ft_split(argv[1], ' ')));
	arg_list = (char **)exit_error(ft_calloc(sizeof(char *), argc));
	i = 0;
	while (argv[++i] != NULL)
	{
		arg_list[i - 1] = exit_error(ft_strdup(argv[i]));
	}
	return (arg_list);
}

void	free_all(t_stack *stack)
{
	ft_lstclear(stack->lst_a, free);
	ft_lstclear(stack->lst_b, free);
	ft_lstclear(stack->lst_ans, NULL);
	free(stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	char	**arg_list;
	int		*tmp;

	stack = exit_error(init_stack());
	arg_list = exit_error(is_valid(init_arg_list(argc, argv)));
	i = -1;
	while (arg_list[++i] != NULL)
	{
		tmp = (int *)ft_calloc(1, sizeof(int));
		*tmp = ft_atoi(arg_list[i]);
		ft_lstadd_back((stack->lst_a), exit_error(ft_lstnew(tmp)));
	}
	free(arg_list);
	if (ft_lstsize(*stack->lst_a) < MINI_SIZE_LIMIT)
		sort_mini_a(stack);
	else
		push_swap(stack, ft_lstsize(*stack->lst_a));
	lst_ans_compose((stack->lst_ans));
	print_lst_str(*(stack->lst_ans));
	free_all(stack);
	return (0);
}
