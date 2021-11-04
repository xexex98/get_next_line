#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 10000

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char) c)
		if (!*str++)
			return (NULL);
	return ((char *) str);
}

char *get_next_line(const)
{
    char *buf;
    int bytes;
	int fd;
	char *next;
	int	i = 0;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd =  open("text.txt", O_RDONLY);
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	if (bytes > 0)
	{
		if (buf[i] != '\n' && buf[i] != '\0')
		{
			while (buf[i] != '\n')
				write(1, &buf[i++], 1);
		}
		if(buf[i] == '\n')
		{
			// printf("ZZZ");
			// i++;
			next = ft_strchr(&buf[i], '\n');
			printf("1%s", next);
		}
		
	}
	return (next);
}

int main()
{
    char *buf;
    int bytes;
	int fd;
	char *next;
	int	i = 0;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd =  open("text.txt", O_RDONLY);
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	if (bytes > 0)
	{
		if (buf[i] != '\n' && buf[i] != '\0')
		{
			while (buf[i] != '\n')
				write(1, &buf[i++], 1);
		}
		if(buf[i] == '\n')
		{
			// printf("ZZZ");
			// i++;
			next = ft_strchr(&buf[i], '\n');
			printf("1%s", next);
		}
		
	}
	return (next);
}