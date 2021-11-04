/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostatoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:09:57 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/01 17:42:29 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*buf;
	char	*line;
    char	*ostatoc;
	int		bytes;
	int		i = 0;
	int j = 0;
	int k = 0;
	char *buf2;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ostatoc = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = read(fd, buf, BUFFER_SIZE);
	buf2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[bytes] = '\0';
	while (buf2[i] != '\0')
	{
		while (buf[i] != '\n')
		{
			ostatoc[j] = buf[i];
			i++;
			j++;
		}
		j = 0;
		while (ostatoc[j] != '\0')
		{
			line[k] = ostatoc[j];
			k++;
			j++;
		}
		free(ostatoc);
	}
	return (line);
}

int main(void)
{
	int fd;
	fd =  open("text.txt", O_RDONLY);
	printf("$$$%s\n", gnl(fd));
	return (0);	
}