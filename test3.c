#include <stdio.h>
#include <stdlib.h>
int main()
{
	size_t	i;
	size_t	len = 1;
	char	*s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	printf("%lu\n", sizeof(char *));
	printf("%lu\n", sizeof(s));
	return (0);
}