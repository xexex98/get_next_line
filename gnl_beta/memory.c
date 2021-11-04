#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 10000

char *gnl(int fd)
{
	int bytes;
	char *buf;
	char *buf2;
	char *line;
	static int i;
	int j;
	int k;
	int z;

	i = 0;
	j = 0;
	k = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	while (buf[i] != '\n')
	{
		buf2[z] = buf[i];
		i++;
		z++;
	}
	while (buf2[j] != '\0')
	{
		line[j] = buf2[k];	
		j++;
		k++;
	}
	k = 0;
	z = 0;
	j = 0;
	i++;
	free(buf2);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd =  open("text.txt", O_RDONLY);
	line = gnl(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}