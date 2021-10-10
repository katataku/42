/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/08 12:38:21 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	ans;

	i = 0;
	ans = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ans = i;
		i++;
	}
	if (c == '\0')
		ans = i;
	if (ans == -1)
		return (0);
	return ((char *) s + ans);
}
