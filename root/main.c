/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/08 14:37:53 by mervyilm         ###   ########.fr       */
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
	
 	reddit(argv[1], map);
	
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			printf("%d", map->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	
/* 	map->mlx_ptr = mlx_init();
	
	// haritaya göre pencere boyutu gönderilecek
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN1, WIN2, "FdF");
	
 	//Putting image
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN1, WIN2);
	map->addr = mlx_get_data_addr(map->img_ptr, &map->bits, &map->width, &map->endian);
	
	my_mlx_pixel_put(map, 5, 5, 0x90e0ef);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, map->x, map->y);

	draw_line(map);
	
	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(map->win_ptr, deal_key, NULL); //tuş göndermek için
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); //pencere kapatmak için
	
	if (get_height(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
	if (get_width(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
		
	system("leaks fdf");
	mlx_loop(map->mlx_ptr);  */
	
}
 
