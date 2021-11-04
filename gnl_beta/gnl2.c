/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:23 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/03 20:57:38 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //#
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1000

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

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
	int			i = 0;
	int			j = 0;
	char		*ret;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}

char	*ft_read(int fd, char *buf2)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	// buf2 = malloc(1);
	// if (!buf2)
		// return (NULL);
	// buf2[0] = '\0';
	while (bytes > 0 && ft_strchr(buf2, '\n') == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buf[bytes] = '\0';
		buf2 = ft_strjoin(buf2, buf); 
	}
	return (buf2);
}

char *ft_remainder(char *buf2)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(100);
	while (buf2[i] && buf2[i] != '\n')
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
//записать остаток в строку и вывести ее;

char	*ft_line_reminder(char *buf2)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf2[i] != '\n')
		i++;
	i++;
	line = malloc(100);
	while (buf2[i] != '\0')
	{
		line[j] = buf2[i];
		j++;
		i++; 
	}
	line[j] = '\0';
	free(buf2);
	return (line);
}

char	*gnl(int fd)
{
	char		*line;
	static char *buf2;

	buf2 = ft_read(fd, buf2);
	line = ft_remainder(buf2);
	buf2 = ft_line_reminder(buf2);
	// printf("4%s\n", line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	// while ((line = gnl(fd)))
	// {
	// 	printf("1%s\n", line);
	// 	free(line);
	// }
	line = gnl(fd);
	printf("1%s\n", line);
	line = gnl(fd);
	printf("2%s\n", line);
	line = gnl(fd);
	printf("3%s\n", line);
	line = gnl(fd);
	printf("4%s\n", line);
	line = gnl(fd);
	printf("5%s\n", line);
	line = gnl(fd);
	printf("6%s\n", line);
	line = gnl(fd);
	printf("7%s\n", line);
	return (0);
}