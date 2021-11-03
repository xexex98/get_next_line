/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:58:10 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/03 22:18:38 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	big = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!big)
		return (NULL);
	while (s1[i] != '\0')
	{
		big[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		big[i++] = s2[j++];
	big[i] = '\0';
	free(s1);
	return (big);
}

char	*ft_read(int fd, char *buf2)
{
	int		bytes;
	char	buf[BUFFER_SIZE + 1];

	bytes = 1;
	// buf2 = malloc(1);
	// buf2[0] = '\0';
	while (bytes > 0 && ft_strchr(buf2, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buf[bytes] = '\0';
		buf2 = ft_strjoin(buf2, buf);
	}
	return (buf2);
}

char	*ft_line(char *buf2)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf2[0])
		return (NULL);
	line = (char *)malloc(sizeof(char) * 100);
	if (!line)
		return (NULL);
	while (buf2[i] != '\n' && buf2[i] != '\0')
	{
		line[i] = buf2[i];
		i++;
	}
	if (buf2[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_line_reminder(char *buf2)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf2[i] != '\n' && buf2[i] != '\0')
		i++;
	if (!buf2[i])
	{
		free(buf2);
		return (NULL);
	}	
	line = (char *)malloc(sizeof(char) * (ft_strlen(buf2) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (buf2[i] != '\0')
	{
		line[j] = buf2[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(buf2);
	return (line);
}

char	*gnl(int fd)
{
	char		*line;
	static char	*buf2;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf2 = ft_read(fd, buf2);
	if (!buf2)
		return (NULL);
	line = ft_line(buf2);
	buf2 = ft_line_reminder(buf2);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	line = gnl(fd);
	printf("%s\n", line);
	return (0);
}
