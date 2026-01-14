/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnouredd <rnouredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:14:08 by rnouredd          #+#    #+#             */
/*   Updated: 2026/01/08 20:14:17 by rnouredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
size_t ft_strlen(char *str);
char *ft_strchr(char *str, int c);
char *ft_strjoin(char *s1, char *s2);
char *extract_line(char *stash);
char *read_and_save(int fd, char *stash);
char *update_stash(char *stash);
char *ft_save(char *stash);

#endif
