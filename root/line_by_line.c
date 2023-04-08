/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/08 16:22:33 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char	*file_name, t_map *map)
{
	int	i;

	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->map = get_next_line(map->fd);
	i = 0;
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
	printf("height: %d\n", map->height);
	printf("width: %d\n", map->width);

	int	i;
	int	fd;
	int size;
	map->map = 0x0;

	size = ((map->height) * (map->width));
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	
	map->matrix = (int **)malloc(sizeof(int) * (size + 1));
	while (i <= map->height)
	{
		map->matrix[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		i++;
	}
		
	i = 0;
	map->map = get_next_line(map->fd);
	while (map->map && map != 0x0)
	{
		//free(map->map);
		map->map = get_next_line(map->fd);
		filled_with(map->matrix[i], map->map);
		i++;
	}
	//map->matrix[i] = 0; 
	close(fd);
}

void	filled_with(int *z_axis, char *line)
{
	char	**coordinates;
	int	i;
	
	coordinates = ft_split(line, ' ');
	i = 0;
	while (coordinates[i])
	{
		z_axis[i] = ft_atoi(coordinates[i]);
		//free(coordinates[i]);
		i++;
	}
	//free(coordinates);
}
