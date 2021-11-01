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
	char	head;
	char	tail;
	char	mask1;
	char	mask2;

	if ((unsigned char)c <= 0x7F)
		write(fd, &c, sizeof(char));
	else
	{
		mask1 = 0b00111111;
		mask2 = 0b11000000;
		head = (((unsigned char)c & mask2) >> 6) | mask2;
		tail = ((unsigned char)c & mask1) | 0b10000000;
		write(fd, &head, 1);
		write(fd, &tail, 1);
	}
}

/*
int main(void)
{
	ft_putchar_fd(0x70, 1);
	ft_putchar_fd(0x99, 1);
}
*/