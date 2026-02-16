/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide.oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:38:10 by tide.oli          #+#    #+#             */
/*   Updated: 2026/02/16 11:38:10 by tide.oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void extract_line(char **stash, char **line, size_t stash_size, size_t line_size)
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
}