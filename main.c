/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 20:53:20 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		return (EXIT_FAILURE);
		
	map = ft_calloc(sizeof(t_map), 1);
	if (map == 0x0)
		return(0);

	map->x = WIN1/2;
	map->y = WIN2/2;
	
	map->mlx_ptr = mlx_init();
	
	// haritaya göre pencere boyutu gönderilecek
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN1, WIN2, "FdF");
	
	//Putting image
 	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN1, WIN2);
	int width = map->width;
	map->addr = mlx_get_data_addr(map->img_ptr, &map->bits, &width, &map->endian);
	//printf("%c", map->box[0][0]);
	
	//my_mlx_pixel_put(map, 5, 5, 0x90e0ef);

	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, map->x, map->y);

	//draw_line(map);
	 
	
	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(map->win_ptr, deal_key, NULL); //tuş göndermek için
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); //pencere kapatmak için
	
	if (get_height(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
	if (get_width(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
	
	map_error(argv[1]);
		
	//system("leaks fdf");
	mlx_loop(map->mlx_ptr);
}
 