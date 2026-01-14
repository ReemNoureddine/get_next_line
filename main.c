/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnouredd <rnouredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:44:27 by rnouredd          #+#    #+#             */
/*   Updated: 2026/01/14 15:44:28 by rnouredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
//     int fd = open("f.txt", O_RDONLY);
//     char* str = get_next_line(fd);
//     printf("%s", str);
//     free (str);
//     return(0);    
// }

int main(void)
{
    int fd = open("f.txt", O_RDONLY);
    char* str;
    while((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
    }
        return(0);    
}

// cc get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=24 before ./a.out
//valgrind --leak-check=full --show-leak-kinds=all ./a.out // check the leaks