int	ft_str_is_numeric(char *str)
{
	int	i;
	int	ans;

	ans = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
		}
		else
		{
			ans = 0;
			break ;
		}
		i++;
	}
	return (ans);
}
