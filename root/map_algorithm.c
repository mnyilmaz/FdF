/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/19 19:03:53 by mervyilm         ###   ########.fr       */
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
	//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	while(map->x > 100)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, 5, 5, 0x003EFF);
		map->x--;
	}

 	while(map->y < 300)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, 5, 5, 0x003EFF);
		map->y++;
	}
}

void	fake_map(t_map *map)
{
	int x = 0;
	int y = 0;
	int i = 7;
	int x_r = (map->x)/2;
	int y_r = (map->y)/2;
	
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	while(y < map->height)
	{
		x = 0;
		x_r = (map->x)/2;
		while (x < map->width)
		{
			//printf("%d ", map->matrix[y][x]);
			if (map->matrix[y][x] != 0)
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, x_r, y_r, 0x8E236B);
			else
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, x_r, y_r, 0xE0EEEE);
			x++;
			x_r += i;
		}
		y_r += i;
		y++;
	}
}

void	draw_line_bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float	dx;
	float	dy;

	dx = x1 - x;
	dy = y1 - y;
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x8E236B);
		x += dx;
		y += dy;
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
