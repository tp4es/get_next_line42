/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:00:42 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/13 22:00:42 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*nstash;
	char		*line;
	char		*temp[BUFFER_SIZE + 1];
	ssize_t		bytes;
	size_t		stash_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes < 0)
		return (NULL);
	if (bytes == 0 && stash == NULL)
		return (NULL);
	else if (bytes == 0 && stash != NULL)
	{
		//Imprime lo que quede en stash
		//Liberar stash
	}
	temp[bytes] = '\0';
	if (!stash)
	{
		stash = malloc(bytes + 1);
		if (!stash)
			return (NULL);
		strcpy(stash, temp);
	}
	else
	{
		stash_len = strlen(stash);
		nstash = malloc(stash_len + bytes + 1);
		if (!nstash)
			return (NULL);
		memcpy(nstash, stash, stash_len);
		memcpy(nstash + stash_len, temp, bytes);
		nstash[stash_len + bytes] = '\0';
		free(stash);
		stash = nstash;
	}
//Imprimir line
//Almacenar el resto en buffer
//Liberar buffer
	return (line);
}