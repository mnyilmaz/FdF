/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 21:58:05 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "minilibx_macos/mlx.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define WIN1 1920
#define WIN2 1080
typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	char	**box;
	char	*map;
	int		endian;
	int		height;
	int		width;
	int		bits;
	int		fd;
	int		x;
	int		y;
	int		z;

	struct s_map *next;
}	t_map;

int		get_height(char	*file_name, t_map *map);
int		get_width(char	*file_name, t_map *map);
char	**ft_split(char const *s, char c);
void	free_str(char **str);
void	*ft_calloc(size_t count, size_t size);
int		close_the_window(void);
int		deal_key(int key, t_map *map);
void	draw_line(t_map *map);
void	my_mlx_pixel_put(t_map *map, int x, int y, int colour);
void	draw_map(t_map *map, char **box);
void	map_error(char *file_name);


#endif
