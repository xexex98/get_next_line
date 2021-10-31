#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
# define BUFFER_SIZE 32

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char) c)
		if (!*str++)
			return (NULL);
	return ((char *) str);
}

int main()
{
    char buf[BUFFER_SIZE];
    int bytes;
	int fd;
	char *next;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd =  open("text.txt", O_RDONLY);
	bytes = read(fd, buf, BUFFER_SIZE);
	
	if (bytes > 0)
	{
		static int i = 0;
		if (buf[i] != '\n' && buf[i] != '\0')
		{
			while (buf[i] != '\n' && i < BUFFER_SIZE)
				write(1, &buf[i++], 1);
			// i++;
			// i++;
		}
		if(buf[i] == '\n' && buf[i] != '\0')
		{
			printf("ZZZ");
			next = ft_strchr(&buf[i], '\n');
			printf("HHHH:%s", next++);
		}
	}
	return 0;
}
