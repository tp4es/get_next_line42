/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:54:59 by tide-oli          #+#    #+#             */
/*   Updated: 2026/04/02 14:55:01 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		temp[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		temp[bytes] = '\0';
		stream_stash(&stash, temp, bytes);
	}
	if (!stash)
		return (NULL);
	return (ft_extract_line(&stash, NULL, ft_strlen(stash)));
}

//Funciones para comprobar y construir líneas
char	*stream_stash(char **stash, char *read_buffer, ssize_t bytes)
{
	char	*temp;

	if (*stash == NULL)
	{
		*stash = malloc(bytes + 1);
		if (!*stash)
			return (NULL);
		ft_strcpy(*stash, read_buffer);
		(*stash)[bytes] = '\0';
	}
	else
	{
		temp = malloc(ft_strlen(*stash) + bytes + 1);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, *stash);
		ft_strncat(temp, read_buffer, bytes);
		free(*stash);
		*stash = temp;
	}
	return (*stash);
}

char	*ft_printable(char **stash, size_t size_line, size_t size_stash)
{
	char	*newline;
	char	*temp;

	newline = malloc(size_line + 1);
	if (!newline)
		return (NULL);
	ft_strncpy(newline, *stash, (size_line));
	temp = malloc((size_stash - size_line) + 1);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, (*stash + size_line));
	free(*stash);
	*stash = temp;
	return (newline);
}

char	*ft_extract_line(char **stash, char *line, size_t size_stash)
{
	size_t	size_line;

	if (!ft_strchr(*stash, '\n'))
	{
		line = malloc(size_stash + 1);
		if (!line)
			return (NULL);
		ft_strcpy(line, *stash);
		free(*stash);
		*stash = NULL;
	}
	else
	{
		size_line = ((ft_strchr(*stash, '\n') - *stash) + 1);
		line = ft_printable(stash, size_line, size_stash);
	}
	return (line);
}
