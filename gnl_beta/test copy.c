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

char *gnl(int fd)
{
	char *buf;
    int bytes;
	char *next;
	char *new;
	int	i = 0;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	if (bytes > 0)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] != '\n')
			{
				// while (buf[i] != '\n')
				// 	write(1, &buf[i++], 1);
				while (buf[i] != '\n')
				{
					new[i] = buf[i];
					i++;
				}
			}
			if(buf[i] == '\n')
			{
				new = ft_strchr(&buf[i++], '\n');
				
			}
			buf = new;
			i++;
		}
	}
	return (buf);
}

int main(void)
{
	int fd;
	fd =  open("text.txt", O_RDONLY);
	printf("$$$%s\n", gnl(fd));
	return (0);	
}