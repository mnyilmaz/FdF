/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/03 01:38:00 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_settings(t_map *map)
{
	map->zoom = 20;
	map->is_iso = 1;
	map->angle = 0.523599;
	map->win_width = 1000;
	map->win_height = 700;
	map->mlx_ptr = mlx_init();
	map->win_ptr =\
	mlx_new_window(map->mlx_ptr, map->win_width, map->win_height, "FdF");
}

int	main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		return (EXIT_FAILURE);
 	map = ft_calloc(sizeof(t_map), 1);
	if (map == 0x0)
		return(0); 
	map->file_name = argv[1];
 	if (get_height(map) == 0x0 || get_width(map) == 0x0)
	{
		write(1, "\033[1;41mMap does not exists! ", 29);
		return (EXIT_FAILURE);
	}
	
	map->win_width = 1000;
	map->win_height = 700;
	map->zoom = 20;
	map->angle = 0.8;
	map->shift = 150;
	map->x = map->win_width/2;
	map->y = map->win_height/2;

	get_int_value_of_the_box(map);
	map->mlx_ptr = mlx_init();
	
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->win_width, map->win_height, "FdF");
	map->zoom = 20;
	
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->win_width, map->height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);

	russian_roulette(map);

	mlx_key_hook(map->win_ptr, deal_key, NULL);
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); 
	mlx_loop(map->mlx_ptr);  
}
