/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:00:48 by tide-oli          #+#    #+#             */
/*   Updated: 2026/02/13 22:00:48 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//stream_line genera el stash y llama funciones
void    stream_lines(char **stash, char *temp, ssize_t bytes)
{
    if (!*stash)
	{
		*stash = malloc(bytes + 1);
		if (!*stash)
			return ;

		strcpy(*stash, temp);
	}
	else
	{
		stash_len = strlen(*stash);
		nstash = malloc(stash_len + bytes + 1);
		if (!nstash)
			return ;
		memcpy(nstash, *stash, stash_len);
		memcpy(nstash + stash_len, temp, bytes);
		nstash[stash_len + bytes] = '\0';
		free(*stash);
		*stash = nstash;
	}
}

void    is_line(char *stash, size_t stash_size, char *line)
{
    size_t  i;

    i = 0;
    while (i < stash_size && stash[i]) //revisar comportamiento cuanto es fin de línea
    {
        if (stash[i] == '\n' || bytes_read == 0)
        {
            extract_line(stash, line, stash_size, i);
            break ;
        }
        i++;
    }
}

char *extract_line(char **stash, char **line, size_t stash_size, size_t line_size)
{
    char    *temp;
    size_t  rest_len;

    rest_len = stash_size - line_size;
    *line = malloc(sizeof(char) * (line_size + 1));
    if (!*line)
        return ;
    strlcpy(*line, *stash, line_size + 1);
    (*line)[line_size] = '\0';
    temp = malloc(sizeof(char) * (rest_len + 1));
    if (!temp)
        return ;
    memcpy(temp, (*stash + line_size), rest_len);
    temp[rest_len] = '\0';
    free(*stash);
    *stash = temp;
    return (*line);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*tsrc;
	unsigned char		*tdest;
	size_t				pos;

	tdest = (unsigned char *)dest;
	tsrc = (const unsigned char *)src;
	pos = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (pos < n)
	{
		tdest[pos] = tsrc[pos];
		pos++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dsize > 0)
	{
		while (dsize > 1 && *src)
		{
			*dst++ = *src++;
			dsize--;
		}
		*dst = 0;
	}
	return (src_len);
}

char    *ft_realloc(char **stash, size_t stash_size, size_t stash_new)
{
    char    *temp;

    temp = malloc(stash_new + 1);
    if(!temp)
        return (NULL);
    ft_memcpy(new, *stash, stash_new);
    free(*stash);
    *stash = temp;
    return (temp);
}
