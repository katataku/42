char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				is_finished;

	is_finished = 0;
	i = 0;
	while (i < n)
	{
		if (is_finished)
		{
			dest[i] = '\0';
		}
		else
		{
			dest[i] = src[i];
			if (src[i] == '\0')
			{
				is_finished = 1;
			}
		}
		i++;
	}
	return (dest);
}
