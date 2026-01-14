/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnouredd <rnouredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:13:47 by rnouredd          #+#    #+#             */
/*   Updated: 2026/01/08 20:17:09 by rnouredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *stash)
{
    int     i;
    int     line_len;
    char    *line_mem;

    if (!stash || stash[0] == '\0')
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        line_len = i + 1;
    else
        line_len = i;
    line_mem = malloc(sizeof(char) * (line_len + 1));
    if (!line_mem)
        return (NULL);
    i = 0;
    while (i < line_len)
    {
        line_mem[i] = stash[i];
        i++;
    }
    line_mem[i] = '\0';
    return (line_mem);
}


char *ft_save(char *stash)
{
    int     i;
    int     j;
    char    *new_stash;

    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i));
    if (!new_stash)
        return (NULL);
    i++;
    j = 0;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *read_and_save(int fd, char *stash)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}


char *get_next_line(int fd)
{
	static char* stash[257];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	stash[fd] = read_and_save(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = ft_save(stash[fd]);
	return (line);
}