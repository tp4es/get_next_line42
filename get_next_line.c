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
	char		temp[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		temp[bytes] = '\0';
		stream_stash(&stash, temp, bytes);
	}
	if (!stash)
		return (NULL);
	return (ft_extract_line(&stash, NULL, ft_strlen(stash)));
}