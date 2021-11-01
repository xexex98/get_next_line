/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test228.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:42:32 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/01 19:26:24 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 2

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char) c)
		if (!*str++)
			return (NULL);
	return ((char *) str);
}

char *gnl(int fd)
{
	int bytes;
	char *buf;
	char *buf2;
	char *line;
	int i;
	static int j;
	int k;
	int z;

	i = 0;
	j = 0;
	k = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf2 = (char *)malloc(sizeof(char) * (200));
	line = (char *)malloc(sizeof(char) * (200));
	if (!buf)
		return (NULL);
	printf("1");
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	if (ft_strchr(buf, '\n') == NULL)
	{
		while(buf[i] != '\0')
		{
			buf2[i] = buf[j];
			i++;
		}
	}
	else
	{
		while(buf[i] != '\n')
		{
			buf2[i] = buf[j];
			i++;
		}
	}
	i = 0;
	while (buf2[i] != '\0' || buf2[i] != '\n')
	{
		line[i] = buf2[i];
		i++;
	}
	i = 0;
	free(buf2);
	// free(buf);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
git 
	fd =  open("text.txt", O_RDONLY);
	line = gnl(fd);
	// while ((line = gnl(fd)))
	// {
		printf("%s", line);
		free(line);
	// }
	return (0);
}