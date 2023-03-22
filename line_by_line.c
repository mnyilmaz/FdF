/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 20:46:37 by mervyilm         ###   ########.fr       */
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
	while (map->map && map != 0x0)
	{
		map->height++;
		//printf("Height: %d\n", map->height);
		free(map->map);
		map->map = get_next_line(map->fd);
	}
	close(map->fd);
	free(map->map);
	printf("Height: %d\n", map->height);
	return(map->height);
}

int	get_width(char	*file_name, t_map *map)
{
	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		return (0);

	int height;
	map->map = get_next_line(map->fd);
	map->box = ft_split(map->map, ' ');

	int j = 0;
	while (map->box[map->width])
	{
		while(map->box[map->width][j] && (j < map->height))
			//free_str(map->box);
			j++;
		if (map->box[map->width][j++] == '\n')
			j = 0;
		printf("%d. indeks: %s\n", map->width, map->box[map->width]);
		map->width++;
	}
	//free(map->map);
	//free_str(map->box);
	close(map->fd);
	system("leaks fdf");
	printf("Width: %d\n", map->width);
	printf("%c", map->box[2][2]);
	return(map->width);
}
