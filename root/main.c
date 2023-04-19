/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/19 19:06:30 by mervyilm         ###   ########.fr       */
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
	
 	if (get_height(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
	if (get_width(argv[1], map) == 0x0)
		return (EXIT_FAILURE); 
	
	map->x = WIN1/2;
	map->y = WIN2/2;

 	reddit(argv[1], map);
	
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			if(map->matrix[i][j] > 9)
				printf("%d ", map->matrix[i][j]);
			else
				printf("%d  ", map->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
 	map->mlx_ptr = mlx_init();
	
	// haritaya göre pencere boyutu gönderilecek
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN1, WIN2, "FdF");
	
 	//Putting image
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN1, WIN2);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	//draw_line(map);
	fake_map(map);
	//draw_line_bresenham(map->x,map->y,5,5,map);
	//actually_draw(map);

	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(map->win_ptr, deal_key, NULL); //tuş göndermek için
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); //pencere kapatmak için
		
	//system("leaks fdf");
	mlx_loop(map->mlx_ptr);  
	
}
 
