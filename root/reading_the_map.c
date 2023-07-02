/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/02 22:52:11 by mervenuryil      ###   ########.fr       */
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
	return(map->height);
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
	return(map->width);
}

void	get_int_value_of_the_box(t_map *map)
{
	int	h;
	int w;

	h = 0;
	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd <= 0)
		return ;
	map->matrix = malloc(sizeof(int *) * (map->height + 1));
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
		free_str(map->box);
	}
	close(map->fd);
}

// int	get_height(char	*file_name)
// {
// 	char	*line;
// 	int		height;
// 	int		fd;

// 	height = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd <= 0)
// 		return (0);
// 	//line = get_next_line(fd);
// 	while((line = get_next_line(fd)))
// 	{
// 		height++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return(height);
// }

// int	get_width(char	*file_name)
// {
// 	char	*line;
// 	int		width;
// 	int		fd;

// 	width = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd <= 0)
// 		return (0);
// 	line = get_next_line(fd);
// 	width = counter(line, ' ');
// 	free(line);
// 	close(fd);
// 	return(width);
// }

// void	box_of_int(int *z, char *line)
// {
// 	char	**box;
// 	int		i;

// 	box = ft_split(line, ' ');
// 	i = 0;
// 	while (box[i])
// 	{
// 		z[i] = ft_atoi(box[i]);
// 		free(box[i]);
// 		i++;
// 	}
// 	free(box);
// }

// void	read_the_map(char	*file_name, t_map	*map)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	map->height = get_height(file_name);
// 	map->width = get_width(file_name);

// 	map->matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
// 	i = 0;
// 	while (i <= map->height)
// 		map->matrix[i++] = (int*)malloc(sizeof(int) * (map->width + 1));
// 	fd = open(file_name, O_RDONLY);
// 	if (fd <= 0)
// 		return ;
// 	i = 0;
// 	//line = get_next_line(fd);
// 	while ((line = get_next_line(fd)))
// 	{
// 		line = get_next_line(fd);
// 		box_of_int(map->matrix[i], line);
// 		free(line);
// 	}
// 	map->matrix[i] = NULL;
// 	close(fd);
// }