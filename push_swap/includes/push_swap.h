/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/22 09:16:16 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_stack
{
	t_list	**lst_a;
	t_list	**lst_b;
}	t_stack;

t_stack	*init_stack(void);
char	**init_arg_list(int argc, char **argv);
void	sa(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
#endif
