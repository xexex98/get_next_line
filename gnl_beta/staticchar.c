/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:51:06 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/03 12:15:21 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void test(char *a)
{
    char *z;
    char *b = "Hi";
    // static char *a;
   	int i = 0;
    static int j = 0;
   
    a[j] = b[i];
    i++;
    j++;
	a[j] ='\0';
    printf("%s", a);
   
}

int main(void)
{
    int i;
    static char *a;
	i = 0;
	a = malloc(sizeof(char) * 1000);
    while (i < 2)
        test(a);
    return (0);
}

// void sample(void)
// {
// 	static char	num = 0;
// 	printf("%i", num++);
// }

// int main(void)
// {
// 	int i = 0;
// 	while (i++ <= 5)
// 		sample();
// 	return (0);
// }
