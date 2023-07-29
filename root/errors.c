/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:47:16 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/30 00:13:32 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdio.h>

void	map_validation_error(t_map *map)
{
	if (get_height(map) == 0x0 || get_width(map) == 0x0)
	{
		write(1, "\033[1;41m Map does not exists! ", 30);
		exit(1);
	}
}

void	map_sizing_error(t_map *map)
{
	int	size;
	int	temp;

	temp = 0;
	size = 0;
	map->fd = open(map->file_name, O_RDONLY);
	map->map = 0x0;
	map->width = 0x0;
	map->map = get_next_line(map->fd);
	size = counter(map->map, ' ');
	while (map->map)
	{
		free(map->map);
		map->map = get_next_line(map->fd);
		temp = counter(map->map, ' ');
		if (temp > size || temp < size)
		{
			write(1, "\033[1;41m Map size is not valid! ", 32);
			exit(1);
		}
	}
	free(map->map);
	close(map->fd);
}

void	extension_error(char *arg)
{
	int		len;

	len = ft_strlen(arg);
	if (arg[len - 4] == '.' && arg[len - 3] == 'f' && arg[len - 2] == 'd' &&\
		arg[len - 1] == 'f' && arg[len] == '\0')
		write (1, "\033[1;45m Map read successfully! \033[0m\n", 37);
	else
	{
		write (1, "\033[1;41m Map extension is not valid! \033[0m\n", 42);
		exit(1);
	}
}

// void	value_error(t_map *map)
// {
// 	int		h;
// 	int		w;

// 	h = 0;
// 	while (h < map->height)
// 	{
// 		w = 0;
// 		while (w < map->width)
// 		{
// 			if (!is_digit(map->matrix[h][w]))
// 			{
// 				write (1, "\033[1;41m Map includes non int value! \033[0m\n", 42);
// 				exit(1);
// 			}
// 			w++;
// 		}
// 		h++;
// 	}
// }

int	ac(int argc)
{
	if (argc != 2)
	{
		write(1, "\033[1;41m Invalid argument number! \033[0m\n", 29);
		return (EXIT_FAILURE);
	}
	return 0;
}

