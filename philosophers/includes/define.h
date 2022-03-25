/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:33:34 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/25 17:20:16 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdbool.h>
# include <stdio.h>
#include <unistd.h>
# define READ_INDEX 0
# define WRITE_INDEX 1

# define STATUS_SUCCESS 0
# define STATUS_FAILURE 1
# define STATUS_MISUSE_BUILTIN 2
# define STATUS_CAN_NOT_EXECUTE 126
# define STATUS_COMMAND_NOT_FOUND 127
#endif
