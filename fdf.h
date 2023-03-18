/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/18 13:23:35 by mervyilm         ###   ########.fr       */
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

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**box;
	char	*map;
	int		height;
	int		width;
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

#endif
