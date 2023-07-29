/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:53:07 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/03 17:18:29 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int	open_the_window(void)
{
	write (1, "Window Opened\n", 15);
	exit(0);
	return (1);
} */

int	close_the_window(void)
{
	write (1, "\033[1;44m Window Closed \033[0m\n", 28);
	exit(0);
	return (1);
}

int	deal_key(int key, t_map *map)
{
	if (key == 53)
	{
		close_the_window();
		mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	}
	return (0);
}
