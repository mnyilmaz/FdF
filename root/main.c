/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/30 00:11:07 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_settings(t_map *map)
{
	int	win_width;
	int	win_height;

	win_width = 1000;
	win_height = 700;
	map->zoom = 20;
	map->angle = 0.8;
	map->shift = 150;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, win_width, win_height, "FdF");
	map->img_ptr = mlx_new_image(map->mlx_ptr, win_width, win_height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	ac(argc);
	map = malloc(sizeof(t_map));
	if (map == 0x0)
		return (0);
	map->file_name = argv[1];
	default_settings(map);
	map_sizing_error(map);
	map_validation_error(map);
	extension_error(map->file_name);
	get_int_value_of_the_box(map);
	draw_map(map);
	mlx_key_hook(map->win_ptr, deal_key, NULL);
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); 
	mlx_loop(map->mlx_ptr);
	free(map);
}
