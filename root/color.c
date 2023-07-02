/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:41:39 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/02 16:43:45 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

// unsigned int char_array_to_hex(char* array)
// {
// 	int				i;
// 	unsigned int	result;

// 	i = 0;
//     result = 0;
//     while (array[i] != '\0')
//     {
//         result = (result << 4) + (array[i] & 0xF);
// 		i++;
//     }
    
//     return result;
// }

// void which_color_to_use(t_map *map)
// {
// 	int h;
// 	int w;

// 	h = 0;
// 	w = 0;
// 	map->cbox = 0x0;
// 	if (find_comma(map->box[h], ',') == 1)
// 	{
// 		map->cbox = ft_split(map->box[h], ',');
// 		while(w < map->width)
// 		{
// 				map->matrix[h][w] = ft_atoi(map->cbox[0]);
// 				map->pixel_color = char_array_to_hex(map->cbox[1]);
// 		}
// 		w++;
// 	}
// 	else
// 		return ;
// 	free_str(map->box);
// }