/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:17:02 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/31 21:48:31 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name get_next_line
// Prototype char *get_next_line(int fd);
// Turn in files get_next_line.c, get_next_line_utils.c,
// get_next_line.h
// Parameters File descriptor to read from
// Return value Read line: correct behavior
// NULL: nothing else to read or an error occurred
// External functs. read, malloc, free
// Description Write a function which returns a line read from a
// file descriptor
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {
// 	char	*buf;
// 	size_t	BUFFER_SIZE = 100;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		perror("open() error");
// 	read(fd, buf, BUFFER_SIZE);
// 	close(fd);
// }

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int	main() {
  int ret, fd;
  char buf[BUFFER_SIZE];

  if ((fd = open("text.txt", O_RDONLY)) < 0)
    perror("open() error");
  else {
    while ((ret = read(fd, buf, sizeof(buf)) == 1)
	{
	  printf("%s", buf);
    }
    close(fd);
  }
}