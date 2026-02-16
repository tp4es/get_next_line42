/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide.oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:34:20 by tide.oli          #+#    #+#             */
/*   Updated: 2026/02/16 12:34:20 by tide.oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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