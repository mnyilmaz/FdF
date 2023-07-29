/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/30 00:11:58 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			**box;
	int				**matrix;
	char			*map;
	char			*file_name;
	unsigned int	pixel_color;
	int				height;
	int				width;
	int				fd;
	
	float			z;
	float			z1;
	double			angle;
	float			zoom;
	float			shift;
	int				is_iso;
}	t_map;

int				counter(char const *s, char c);
char			**ft_split(char const *s, char c);
void			free_str(char **str);
void			*ft_calloc(size_t count, size_t size);
int				close_the_window(void);
int				deal_key(int key, t_map *map);
int				ft_atoi(char *s);
int				get_height(t_map *map);
int				get_width(t_map *map);
void			get_int_value_of_the_box(t_map *map);
unsigned int	color_picker(float x, float y, t_map *map);
void			draw_line(float x, float y, float x1, float y1, t_map *map);
void			draw_map(t_map *map);
int				ac(int argc);
void			map_validation_error(t_map *map);
void			map_sizing_error(t_map *map);
void			extension_error(char *arg);





#endif
