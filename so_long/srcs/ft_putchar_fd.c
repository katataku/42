/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putchar_fd.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: takkatao <takkatao@student.42tokyo.jp>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/08 15:04:44 by takkatao		  #+#	#+#			 */
/*   Updated: 2021/10/27 19:39:26 by takkatao		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	tmp;

	tmp = write(fd, &c, sizeof(char));
	(void)tmp;
}
