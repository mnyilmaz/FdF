/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:04 by mervyilm         ###   ########.fr       */
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
	write (1, "asd\n", 4);
	exit(0);
	return (1);
}
int	main(void)
{
	t_fdf *data;

	data = malloc(sizeof(t_fdf));
	if (data == 0x0)
		return(1);
	
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 400, 400, "MLX Window");
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 200, 200, 0x90e0ef);
	
	//This function allows user to deal with a key
	//Using this will allow writig on the terminal when pressed X
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	 mlx_hook(data->win_ptr, 17, 0, close_the_window, (void *)0);
	
	mlx_loop(data->mlx_ptr);
}
