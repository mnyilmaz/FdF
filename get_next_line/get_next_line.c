/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:51:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 15:02:30 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(char *chr, int fd, char **schr)
{
	char	*temp;
	int		rd;

	if (!*schr || !ft_strchr(*schr, '\n'))
	{
		rd = read(fd, chr, BUFFER_SIZE);
		while (rd > 0)
		{
			chr[rd] = 0;
			if (!*schr)
				*schr = ft_substr(chr, 0, rd);
			else
			{
				temp = *schr;
				*schr = ft_strjoin(*schr, chr);
				free(temp);
			}
			if (ft_strchr(chr, '\n'))
				break ;
			rd = read(fd, chr, BUFFER_SIZE);
		}
	}	
	free(chr);
}

static int	fin(int point, char **schr)
{
	if (point == 1)
		return (ft_strlen(*schr) - ft_strlen(ft_strchr(*schr, '\n')) + 1);
	if (point == 2)
		return (ft_strlen(ft_strchr(*schr, '\n')) - 1);
	return (0);
}

char	*not_new_line(char **schr)
{
	char	*temp;
	char	*line;

	if (!*schr)
		return (0);
	if (!ft_strchr(*schr, '\n'))
	{
		if (!ft_strlen(*schr))
		{
			free(*schr);
			*schr = 0;
			return (0);
		}
		line = ft_substr(*schr, 0, ft_strlen(*schr));
		free(*schr);
		*schr = 0;
	}
	else
	{
		line = ft_substr(*schr, 0, fin(1, schr));
		temp = *schr;
		*schr = ft_substr(ft_strchr(*schr, '\n'), 1, fin(2, schr));
		free(temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*schr;
	char		*chr;

	chr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chr)
		return (0);
	if (read(fd, chr, 0) == -1 || fd == -1 || BUFFER_SIZE < 1)
	{
		free(chr);
		free(schr);
		return (0);
	}
	read_line(chr, fd, &schr);
	return (not_new_line(&schr));
}
