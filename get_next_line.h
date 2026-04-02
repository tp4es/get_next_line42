/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:55:42 by tide-oli          #+#    #+#             */
/*   Updated: 2026/04/02 14:55:45 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_extract_line(char **stash, char *line, size_t stash_size);
char	*stream_stash(char **stash, char *temp, ssize_t bytes);
char	*ft_printable(char **stash, size_t size_line, size_t size_stash);
#endif
