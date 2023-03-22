/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 20:20:54 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda_algorithm(t_map *map)
{
	//mlx
	
}

void	my_mlx_pixel_put(t_map *map, int x, int y, int colour)
{
	char	*dst;
	int width = map->width;

	dst = map->addr + (y * width + x * (map->bits / 8));
	*(unsigned int*)dst = colour;
}

void	draw_line(t_map *map)
{
	while(map->x > 100)
	{
		my_mlx_pixel_put(map, 5, 5, 0x90e0ef);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, map->x, map->y);
		map->x--;
	}

 	while(map->y < 300)
	{
		my_mlx_pixel_put(map, 5, 5, 0x90e0ef);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, map->x, map->y);
		map->y++;
	}
}

void	draw_map(t_map *map, char **box)
{
	int row;
	int col;
	int	x;
	int	y;

	x = WIN1 / 2;
	y = WIN2 / 2;
	row = map->width;
	col = map->height;
	box = map->box;
	while (box[row])
	{
		col = 0;
		while(box[row][col])
		{
			my_mlx_pixel_put(map, x, y, 0x90e0ef);
			x++;
			col--;
		}
		row--;
	}
	
}
