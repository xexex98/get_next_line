
char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (s[i])
	{	
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}