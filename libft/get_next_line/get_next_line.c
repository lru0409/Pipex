/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:51:18 by rolee             #+#    #+#             */
/*   Updated: 2024/05/10 19:11:00 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*read_line(int fd, char *buffer, char *storage);
static char	*separate_by_newline(char *line);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, storage);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = separate_by_newline(line);
	return (line);
}

static char	*read_line(int fd, char *buffer, char *storage)
{
	int		read_byte;
	char	*temp;

	while (ft_strchr(storage, '\n') == NULL)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = 0;
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (!storage)
			return (NULL);
	}
	return (storage);
}

static char	*separate_by_newline(char *line)
{
	int		idx;
	char	*storage;

	idx = 0;
	while (line[idx] != '\n' && line[idx])
		idx++;
	if (line[idx] == 0)
		return (NULL);
	storage = ft_substr(line, idx + 1, ft_strlen(line) - idx - 1);
	if (!storage)
		return (NULL);
	if (storage[0] == 0)
	{
		free(storage);
		storage = NULL;
	}
	line[idx + 1] = 0;
	return (storage);
}
