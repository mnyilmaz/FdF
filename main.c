/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 17:31:45 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int close_the_window(void)
{
	write (1, "Window Closed\n", 14);
	exit(0);
	return (1);
}

int deal_key(int key, void *param)
{
	(void)param;
	system("leaks fdf");
	if (key == 53)
		close_the_window();
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
		return (EXIT_FAILURE);
	map = ft_calloc(sizeof(t_map), 1);
	if (map == 0x0)
		return(0);
		
	map->x = 200;
	map->y = 200;
	map->height = 0;
	map->width = 0;
	map->mlx_ptr = mlx_init();
	// haritaya göre pencere boyutu gönderilecek
	map->win_ptr = mlx_new_window(map->mlx_ptr, 400, 400, "MLX Window");
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x, map->y, 0x90e0ef);

	while(map->x > 100)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x, map->y, 0xF2E9E4);
		map->x--;
	}

 	while(map->y < 300)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x, map->y, 0xF2E9E4);
		map->y++;
	}
	
	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(map->win_ptr, deal_key, NULL); //tuş göndermek için
	mlx_hook(map->win_ptr, 17, 0, close_the_window, (void *)0); //pencere kapatmak için
	if (get_height(argv[1], map) == 0x0)
		return (EXIT_FAILURE);
	if (get_width(argv[1], map) == 0x0)
		return (EXIT_FAILURE);

	mlx_loop(map->mlx_ptr);
}
