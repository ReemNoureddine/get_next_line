/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnouredd <rnouredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:13:40 by rnouredd          #+#    #+#             */
/*   Updated: 2026/01/14 15:42:36 by rnouredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i ++;
	}
	if (c == '\0')
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i ++;
	}
	while (s2 != NULL && s2[j] != '\0' )
	{
		s3[i ++] = s2[j ++];
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}
