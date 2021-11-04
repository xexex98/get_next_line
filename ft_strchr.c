#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 1000

// char	*ft_strchr(const char *str, int c)
// {
// 	while (*str != (char) c)
// 		if (!*str++)
// 			return (NULL);
// 	return ((char *) str);
// }

// char *ft_strchr(char *str, char c)
// {
// 	if (!str)
// 		return (NULL);
// 	while (*str++)
// 		if (*str == c)
// 			return((char *)str);
// 	return (NULL);
// }

// char *ft_strchr(char *str, char c)
// {
// 	int i;

// 	i = 0;

// 	if (!str)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return(&str[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int main()
{
    char *str = "123\n4";
    int bytes;
	int fd;
	char *next;
	int i = 0;
	if (!ft_strchr(str, '1'))
	{
		i = 0;
	}
	else
		i = 1;
	// printf("%s", ft_strchr(str, '4'));
	printf("%i", i);
}