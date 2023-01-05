/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirvent <asirvent@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:36:13 by asirvent          #+#    #+#             */
/*   Updated: 2022/12/07 21:36:22 by asirvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (*str++ != '\0')
	{
		if (*str == (char)c)
			return ((char *)&*str);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free_null(&s1));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (free_null(&s1));
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*free_null(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*ducci_free(char **ptr, char **line)
{
	free(*ptr);
	*ptr = NULL;
	if (*line)
	{
		free(*line);
		line = NULL;
	}
	return (NULL);
}
