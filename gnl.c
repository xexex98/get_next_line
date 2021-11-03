/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:37:38 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/03 18:06:02 by mbarra           ###   ########.fr       */
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
	if (!s2)
		return (NULL);
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
	int		bytes = 1;

	bytes = 1;
	// buf2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1) * 100); //netaknado
	while (bytes > 0 && ft_strchr(buf2, '\n') == NULL)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buf[bytes] = '\0';
		buf2 =  ft_strjoin(buf2, buf);
	}
	return (buf2); //вернул 1 строку и дальше столько символов сколько передавалось в буффер вместе с \n 
	//эти потерянные символы нужно вернуть или записать куда нибудь
}

char	*ft_line(char *buf2)
{
	char	*line;
	int 	i;

	i = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1) * 100); //netaknado
	while (buf2[i] != '\n' && buf2[i])
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
	return (line); //убрал лишнее из буфера 2 и оставил только 1 стркоу сохранив перенос строки
}
// теперь нужно вернуть оставшиеся строки. нужно подать в буфер2 2 строку прогнать ее по циклам и вернуть в line 2 строку.


char *freedom(char *buf2)
{
	char *line;
	int i = 0;
	int j = 0;
	
	
	while (buf2[i] && buf2[i] != '\n')
		i++;
	i++;
	if (!buf2[i])
	{
		free(buf2);
		return (NULL);
	}
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1) * 100);
	if (!line)
		return (NULL);
	while(buf2[i])
	{
		line[j] = buf2[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(buf2);
	return(line);
}

char	*ft_get_next_line(int fd)
{
	static char	*buf2;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf2 = ft_read(fd, buf2); //вернул buf2 в котором содержится строка до первого переноса
	if (!buf2)
		return (NULL);
	line = ft_line(buf2); //записал в line первую строку файла
	//нужно освободить буффер2 записать туда 2 строку из буффера
	// free(buf2);
	buf2 = freedom(buf2);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	// line = ft_line(fd);
	
	// printf("1%s", line);
	// printf("2%s", ft_get_next_line(fd));
	// printf("3%s", freedom(line));
	// while ((line = ft_get_next_line(fd)))
	// {
	// 	printf("1%s", line);
	// 	free(line);
	// }
	// line2 = ft_line(line);
	line = ft_get_next_line(fd);
	printf("1%s", line);

	line = ft_get_next_line(fd);
	printf("1%s", line);

	line = ft_get_next_line(fd);
	printf("1%s", line);
	return (0);
}
