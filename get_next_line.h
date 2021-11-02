/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:49:54 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/01 15:34:30 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	ft_strcpy(char *dst, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
