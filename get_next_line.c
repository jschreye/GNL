/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:11:11 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/25 10:36:58 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//# define BUFFER_SIZE 10

char	*readline(char *str);
void	freeptr(char *ptr);
int		checkline(char *str);
char	*trucdemerde(char **save, int stockage, int fd);

char	*get_next_line(int fd)
{
	static char	*save;
	int			stockage;

	stockage = 0;
	if (!save)
		save = ft_strdup("");
	else
		save = ft_strdup(&save[checkline(save) + 1]);
	if (fd < 0 || BUFFER_SIZE <= 0 || save == 0)
		return (NULL);
	return (trucdemerde(&save, stockage, fd));
}

void	freeptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}	
int	checkline(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0' && str[c] != '\n')
		c++;
	return (c);
}

char	*trucdemerde(char **save, int stockage, int fd)
{
	char	*tmp;
	char	*result;
	char	*ptr;

	stockage = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && stockage != 0)
	{
		stockage = read(fd, tmp, BUFFER_SIZE);
		if (stockage == -1)
			return (NULL);
		tmp[stockage] = '\0';
		ptr = *save;
		*save = ft_strjoin(*save, tmp);
		freeptr(ptr);
		if (tmp[stockage] == '\n')
			break;
	}
	result = ft_substr(*save, 0, checkline(*save) + 1);
	return (result);
}
/*int main()
{
	int	fd;

	fd = open("text", O_RDONLY);
	if (fd == - 1)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);	
}*/
