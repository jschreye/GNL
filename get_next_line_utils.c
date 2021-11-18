/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:49:40 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/18 10:46:16 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
// compte la taille de ma string

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dst;

	size = ft_strlen(s1) + 1;
	dst = malloc(size * sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*dst = *s1;
		dst++;
		s1++;
	}
	*dst = '\0';
	return (dst - size + 1);
}
// duplique ma chaine de caractere dans destination

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == '\0')
			return (0);
		else if ((char)c == *str)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (0);
}
// recherche la premiere occurence demande dans ma string 

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	taille;
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	if (start > taille)
		len = 0;
	else if (start + len > taille)
		len = taille - start;
	dst = malloc(taille * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i2 < len)
			dst[i2++] = s[i];
		i++;
	}
	dst[i2] = '\0';
	return (dst);
}
// copie a partir de start le nombre de len caractere de s dans dst

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		total;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(total * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		str[i + i2] = s2[i2];
		i2++;
	}
	str[i + i2] = '\0';
	return (str);
}
// met ensmble deux string dans une si la taille allouee et suffisante
