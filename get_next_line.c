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
		return ();
	while ()
	{
	}
	return (line);
}