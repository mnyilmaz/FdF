/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/11 17:17:17 by mervyilm         ###   ########.fr       */
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



typedef struct s_fdf
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;

	struct s_fdf *next;
}	t_fdf;


int	get_height(char	*file_name);
int	get_width(char	*file_name);

#endif
