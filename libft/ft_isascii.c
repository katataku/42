#include "libft.h"

int	ft_isascii(int c)
{
	int	ans;

	ans = FALSE;
	if (0 <= c && c <= 127 )
		ans = TRUE;
	return (ans);
}
