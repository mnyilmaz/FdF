/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 15:30:07 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


int	get_height(char	*file_name)
{
	int	i;
	int	fd;
	int	height;
	char	*str;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	height = 0;
	str = get_next_line(fd);
	while(str)
	{
		free(str);
		str = get_next_line(fd);

		height++;
	}
	close(fd);
	printf("Height: %d\n", height);
	return(height);
}

int	get_width(char	*file_name)
{
	int	i;
	int	fd;
	int	height;
	char	*str;
	char	**box;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	
	i = 0;
	height = get_height(file_name);
	while (height)
	{
		str = get_next_line(fd);
		box = ft_split(str, ' ');
		while(box[i])
		{
				printf("test\n");
				box = ft_split(str, ' ');
				printf("%d. indeks: %s\n", i, box[i]);
				i++;
				free_str(box);
		}
		free(str);
		height--;
	}
	printf("Width: %d\n", i);
	//free_str(box);
}
