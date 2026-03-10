/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide.oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:51:53 by tide.oli          #+#    #+#             */
/*   Updated: 2026/03/10 13:51:53 by tide.oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Funciones manejar strings
char    *ft_strcpy(char *dst, const char *src)
{
    size_t  i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t  i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char    *ft_strncat(char *dst, const char *src, size_t n)
{
    size_t  dst_len;
    size_t  i;

    dst_len = ft_strlen(dst);
    i = 0;
    while (i < n && src[i])
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst);
}

char	*ft_strchr(char *s, int c)
{
	size_t  i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
//Función para liberar memoria y asignar nueva memoria al stash
void    ft_restash(char **stash, size_t size_new)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(size_new + 1);
	if(!temp)
		return ;
	while (i < size_new)
	{
		temp[i] = (*stash)[i];
		i++;
	}
	temp[i] = '\0';
	free(*stash);
	*stash = temp;
}

//Funciones para comprobar y construir líneas
char    *stream_stash(char **stash, char *read_buffer, ssize_t bytes)
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

char	*ft_extract_line(char **stash, char *line, size_t stash_size)
{
	size_t	line_size;
	char	*temp;

	if (!ft_strchr(*stash, '\n'))
	{
		line = malloc(stash_size + 1);
		if (!line)
			return (NULL);
		ft_strcpy(line, *stash);
	}
	else
	{
		line_size = ((ft_strchr(*stash, '\n') - *stash) + 1);
		line = malloc(line_size + 1);
		if (!line)
			return (NULL);
		ft_strncpy(line, *stash, (line_size + 1));
		temp = malloc((stash_size - line_size) + 1);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, (*stash + line_size));
		free(*stash);
		*stash = temp;
	}
	return (line);
}