/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:57:16 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/24 15:04:54 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while(str[c])
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1,char const *s2)
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

char	*ft_strchr(const char *s, int c)
{
	char    *str;

	str = (char *)s;
	while (*str)
	{
		if (*str == '\0')
			return (0);
		else if ((char)c == *str)
		{
			return (str);
		}
		str++;
	}
 	if ((char)c == '\0')
		return (str);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1) + 1;
	dest = malloc(size * sizeof(*dest));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (dest - size + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	unsigned int		taille;
	unsigned int		i;
	unsigned int		i2;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	if (start > taille)
		len = 0;
	else if (start + len > taille)
		len = taille - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i2 < len)
			dest[i2++] = s[i];
		i++;
	}
	dest[i2] = '\0';
	return (dest);
}
