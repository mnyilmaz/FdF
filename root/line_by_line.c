/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calypso <calypso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/18 01:35:56 by calypso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char	*file_name, t_map *map)
{
	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->map = get_next_line(map->fd);
	while (map->map)
	{
		map->height++;
		//free(map->map);
		map->map = get_next_line(map->fd);
	}
	close(map->fd);

	//free(map->map);
	//printf("Height: %d\n", map->height);
	return(map->height);
}

int	get_width(char	*file_name, t_map *map)
{
	int h;

	h = map->height;
	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		return (0);
	
	map->width = 0;
	while (h)
	{
		map->map = get_next_line(map->fd);
		map->box = ft_split(map->map, ' ');
		while (map->box[map->width])
		{
			free_str(map->box);
			map->box = ft_split(map->map, ' ');
			//printf("%d. indeks: %s\n", map->width, box[map->width]);
			map->width++;
		}
		//free(map->map);
		//free_str(map->box);
		h--;
	}
	//printf("Width: %d\n", map->width);
	close(map->fd);
	return(map->width);
}

void	reddit(char *file_name, t_map *map)
{
	int	i;
	int j;
	//map->map = 0x0;

	i = 0;
	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		return ;
	
	map->matrix = malloc(sizeof(int *) * (map->height));
	while (i < map->height)
	{
		j = 0;
		map->map = get_next_line(map->fd);
		map->box = ft_split(map->map, ' ');
		map->matrix[i] = malloc(sizeof(int) * (map->width));
		while (j < map->width)
		{
			map->matrix[i][j] = ft_atoi(map->box[j]);
			j++;
		}
		i++;
	}
	close(map->fd);
}