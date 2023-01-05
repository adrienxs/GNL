/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirvent <asirvent@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:27:44 by asirvent          #+#    #+#             */
/*   Updated: 2022/12/07 16:27:47 by asirvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *data)
{
	int		i;
	char	*str;

	i = 0;
	if (!data[i])
		return (NULL);
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (data[++i] != '\0' && data[i] != '\n')
		str[i] = data[i];
	if (data[i] == '\n')
	{
		str[i] = data[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_next_line(char *data)
{
	int		i;
	char	*aux;
	char	*str;

	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	if (!data[i])
		return (free_null(&data));
	str = malloc((ft_strlen(data) - i++ + 1) * sizeof(char));
	if (!str)
		return (free_null(&data));
	aux = str;
	while (data[i] != '\0')
		*str++ = data[i++];
	*str = '\0';
	free(data);
	return (aux);
}

char	*save_line(int fd, char	*data)
{
	int		nbr_bytes;
	char	*buffer;

	nbr_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_null(&buffer));
	while (!ft_strchr(data, '\n') && nbr_bytes > 0)
	{
		nbr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nbr_bytes == -1)
			return (ducci_free(&buffer, &data));
		buffer[nbr_bytes] = '\0';
		data = ft_strjoin(data, buffer);
	}
	free(buffer);
	return (data);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*data;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	data = save_line(fd, data);
	if (!data)
		return (NULL);
	line = make_line(data);
	if (!line)
		return (free_null(&data));
	data = save_next_line(data);
	return (line);
}
