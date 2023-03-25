/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:53:07 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/18 18:16:21 by mervyilm         ###   ########.fr       */
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
	write (1, "Window Closed\n", 15);
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

int	put_image(void)
{
	return(1);
}
