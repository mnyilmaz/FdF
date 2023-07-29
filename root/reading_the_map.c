/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/30 00:13:17 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(t_map *map)
{
	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd <= 0)
		return (0);
	map->height = 0x0;
	map->map = get_next_line(map->fd);
	while (map->map)
	{
		map->height++;
		free(map->map);
		map->map = get_next_line(map->fd);
	}
	free(map->map);
	close(map->fd);
	return (map->height);
}

int	get_width(t_map *map)
{
	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd <= 0)
		return (0);
	map->map = 0x0;
	map->width = 0x0;
	map->map = get_next_line(map->fd);
	map->box = ft_split(map->map, ' ');
	while (map->box[map->width])
		map->width++;
	free(map->map);
	free_str(map->box);
	close(map->fd);
	return (map->width);
}

void	get_int_value_of_the_box(t_map *map)
{
	int	h;
	int	w;

	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd <= 0)
		return ;
	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	h = 0;
	while (h < map->height)
	{
		w = 0;
		map->map = get_next_line(map->fd);
		map->box = ft_split(map->map, ' ');
		map->matrix[h] = malloc(sizeof(int) * (map->width + 1));
		while (w < map->width)
		{
			map->matrix[h][w] = ft_atoi(map->box[w]);
			w++;
		}
		h++;
		free(map->map);
	}
	free_str(map->box);
	close(map->fd);
}
