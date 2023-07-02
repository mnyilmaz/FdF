/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/03 01:27:42 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define MAX(a,b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

// void	my_mlx_pixel_put(t_map *map, int x, int y, int colour)
// {
// 	char	*dst;

// 	dst = map->addr + (y * map->width + x * (map->bits / 8));
// 	*(unsigned int*)dst = colour;
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

void	zoomed(float *x, float *y, float *x1, float *y1, t_map *map)
{
	*x *= map->zoom;
	*x1 *= map->zoom;
	*y *= map->zoom;
	*y1 *= map->zoom;
}

void	spin_me_right_round(float *x, float *y, float *x1, float *y1, t_map *map)
{
	*x += map->shift;
	*x1 += map->shift;
	*y += map->shift;
	*y1 += map->shift;
}

void	isometric(float *x, float *y, int z, t_map *map)
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

void	russian_draw(float x, float y, float x1, float y1, t_map *map)
{
	float	dx;
	float	dy;
	int		max;

	map->pixel_color = color_picker(x, y, map);
	get_z(x, y, x1, y1, map);
	zoomed(&x, &y, &x1, &y1, map);
	isometric(&x, &y, map->z, map);
	isometric(&x1, &y1, map->z1, map);
	spin_me_right_round(&x, &y, &x1, &y1, map);
	dx = x1 - x;
	dy = y1 - y;
	max = MAX(MOD(dx),MOD(dy));
	dx /= max;
	dy /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->pixel_color);
		x += dx;
		y += dy;
	}	
}

void	russian_roulette(t_map *map)
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
				russian_draw(x, y, x + 1, y, map);
			if (y < map->height)
				russian_draw(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
