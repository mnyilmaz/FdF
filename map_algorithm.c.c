/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:30:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/18 18:18:12 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda_algorithm(t_map *map)
{
	//mlx
	
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

void	my_mlx_pixel_put(t_map *map, int x, int y, int colour)
{
	char	*dst;

	dst = map->addr + (y * map->width + x * (map->bits / 8));
	*(unsigned int*)dst = colour;
}