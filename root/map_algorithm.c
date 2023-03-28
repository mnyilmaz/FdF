/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calypso <calypso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/26 00:18:46 by calypso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int colour)
{
	char	*dst;

	dst = map->addr + (y * map->width + x * (map->bits / 8));
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

void	draw_line_bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float	x_road;
	float	y_road;
	
	x_road = x1 - x;
	y_road = y1 - y;
	while ((int)(x - x1)  || (int)(y - y1))
	{
		my_mlx_pixel_put(map, x, y, 0x90e0ef);
		x += x_road;
		y += y_road;
	}
}

void	actually_draw(t_map *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_line_bresenham(x, y, x+1, y, map);
			draw_line_bresenham(x, y, x, y+1, map);
			x++;
		}
		y++;
	}
}
