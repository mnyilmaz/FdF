/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 15:02:36 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (0);
}

// int close_the_window(int button, void *param, t_fdf *ex)
// {
// 	write(1, "window closed", 13);
// 	// mlx_clear_window(ex->mlx_ptr, ex->win_ptr);
// 	// free(ex->win_ptr);
// 	exit(1);
// 	return (0);
// ESC: 53
// }

int close_the_window(void)
{
	write (1, "Window Closed\n", 14);
	exit(0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fdf *data;

	data = malloc(sizeof(t_fdf));
	if (data == 0x0)
		return(1);
	int	x;
	int	y;

	x = 200;
	y = 200;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 400, 400, "MLX Window");
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x90e0ef);

	while(x > 100)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xF2E9E4);
		x--;
	}

 	while(y < 300)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xF2E9E4);
		y++;
	}
	
	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_hook(data->win_ptr, 17, 0, close_the_window, (void *)0);

	get_width(argv[1]);
	get_height(argv[1]);
	
	mlx_loop(data->mlx_ptr);
}
