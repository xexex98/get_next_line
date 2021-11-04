/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:58:10 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/04 18:23:45 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf2)
{
	int		bytes;
	char	buf[BUFFER_SIZE + 1];

	bytes = 1;
	// buf2 = malloc(1);
	// buf2[0] = '\0';
	while (bytes > 0 && !ft_strchr(buf2, '\n'))
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
		line[j++] = buf2[i++];
	line[j] = '\0';
	free(buf2);
	return (line);
}

char	*get_next_line(int fd)
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
	while ((line = get_next_line(fd)))
	{
		printf("1%s", line);
		free(line);
	}
	return (0);
}
