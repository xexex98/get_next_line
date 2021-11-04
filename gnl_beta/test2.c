#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    char buff[2];
	int fd = open("text.txt", O_RDONLY);
    int bytes = read(fd, buff, sizeof buff); /* 0 is stdin's file descriptor */
    if (bytes > 0)
    {
        int i;
        for (i = 0; i < bytes; ++i)
        {
            printf("%d : %c\n", i, buff[i]);
        }
    }
    return 0;
}