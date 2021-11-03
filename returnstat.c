/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:48:47 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/03 13:02:39 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 5

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return(&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	big = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!big)
		return (NULL);
	while (str1[i])
	{
		big[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		big[i++] = str2[j++];
	}
	big[i] = '\0';
	return (big);
}

char	*ft_read(int fd, char *buf2)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	int		i;

	bytes = 1;
	i = 0;
	buf2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1) * 100); //netaknado
	while (bytes > 0 && ft_strchr(buf2, '\n') == NULL)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buf[bytes] = '\0';
		buf2 =  ft_strjoin(buf2, buf);
	}
	return (buf2);
}


char	*ft_get_next_line(fd)
{
	static char	*buf2;
	char	*line;
	char	*line2;
	char	*line3;

	line = ft_read(fd, buf2); //вернул buf2 в котором содержится строка до первого переноса
	// line2 = ft_line(line); //записал в line первую строку файла
	//нужно освободить буффер2 записать туда 2 строку из буффера
	// free(buf2);s
	// line3 = freedom(buf2);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	// line = ft_line(fd);
	line = ft_get_next_line(fd);
	// while ((line = ft_get_next_line(fd)))
	// {
	// 	printf("1%s", line);
	// 	free(line);
	// }
	// line2 = ft_line(line);
	printf("1%s", line);
	return (0);
}
