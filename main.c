/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:44 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/10 19:03:02 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (0);
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
	mlx_key_hook(data->win_ptr, deal_key, (void *)0);

	mlx_loop(data->mlx_ptr);
}
