/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/10 18:53:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_count(char **argv, char *str)
{
	int	cnt;
	int	i;
	int	len;

	cnt = 0;
	i = -1;
	while (argv[++i] != NULL)
	{
		if (ft_strlen(argv[i]) < ft_strlen(str))
			len = ft_strlen(str);
		else
			len = ft_strlen(argv[i]);
		if (ft_strncmp(argv[i], str, len) == 0)
			cnt++;
	}
	if (cnt > 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

char	**validate_arg_list(char **argv)
{
	int	i;

	if (argv == NULL)
		return (NULL);
	i = -1;
	while (argv[++i] != NULL)
	{
		ft_atoi(argv[i]);
		validate_count(argv, argv[i]);
	}
	return (argv);
}
