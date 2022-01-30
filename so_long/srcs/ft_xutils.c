#include "so_long.h"

char	*ft_xcalloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = ft_calloc(count, size);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(1);
	}
	return (tmp);
}
