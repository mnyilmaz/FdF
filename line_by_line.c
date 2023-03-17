/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 17:29:17 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


int	get_height(char	*file_name, t_map *map)
{
	int	fd;
	char	*str;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str && map != 0x0)
	{
		map->height++;
		//printf("Height: %d\n", map->height);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
//	printf("Height: %d\n", map->height);
	return(map->height);
}

int	get_width(char	*file_name, t_map *map)
{
	int	fd;
	char	*str;
	char	**box;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	
	//map->height = get_height(file_name);
	while (map->height)
	{
		str = get_next_line(fd);
		box = ft_split(str, ' ');
		while (box[map->width])
		{
			free_str(box);
			box = ft_split(str, ' ');
			//printf("%d. indeks: %s\n", map->width, box[map->width]);
			map->width++;
		}
		free(str);
		free_str(box);
		map->height--;
	}
	//printf("Width: %d\n", map->width);
	close(fd);
	return(map->width);
}
