/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/03 02:19:23 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	my_mlx_pixel_put(t_map *map, int x, int y)
// {
// 	char	*dst;

// 	dst = map->addr + (y * map->width + x * (map->bits / 8));
// 	*(unsigned int*)dst = map->pixel_color;
// }

unsigned int	color_picker(float x, float y, t_map *map)
{
	int w;
	int h;
	w = (int)x;
	h = (int)y;
	
	if (h < map->height)
	{
		if(w <map->width)
		{
			if (map->matrix[h][w] != 0)
				map->pixel_color = 0xFFFFFF;
			else
				map->pixel_color =  0xFF0000;
		}
	}
	return(map->pixel_color);
}

void	zoom(float *x, float *y, float *x1, float *y1, t_map *map)
{
	*x *= map->zoom;
	*x1 *= map->zoom;
	*y *= map->zoom;
	*y1 *= map->zoom;
}

void	shift(float *x, float *y, float *x1, float *y1, t_map *map)
{
	*x += map->shift;
	*x1 += map->shift;
	*y += map->shift;
	*y1 += map->shift;
}

void	isometry(float *x, float *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(map->angle);
	*y = (*x + *y) * sin(map->angle) - z;
}

void	get_z(float x, float y, float x1, float y1, t_map *map)
{
	if ((int)y < map->height && (int)y1 < map->height)
	{
		if ((int)x < map->width && (int)x1 < map->width)
		{
			map->z = map->matrix[(int)y][(int)x];
			map->z1 = map->matrix[(int)y1][(int)x1];
		}
	}
}

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	dx;
	float	dy;
	int		max;

	map->pixel_color = color_picker(x, y, map);
	get_z(x, y, x1, y1, map);
	zoom(&x, &y, &x1, &y1, map);
	isometry(&x, &y, map->z, map);
	isometry(&x1, &y1, map->z1, map);
	shift(&x, &y, &x1, &y1, map);
	dx = x1 - x;
	dy = y1 - y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		//my_mlx_pixel_put(map, x, y);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->pixel_color);
		x += dx;
		y += dy;
	}	
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y <= map->height)
	{
		x = 0;
		while (x <= map->width)
		{
			if (x < map->width)
				draw_line(x, y, x + 1, y, map);
			if (y < map->height)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
