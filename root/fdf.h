/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/03 01:24:43 by mervenuryil      ###   ########.fr       */
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

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	char			**box;
	char			**cbox;
	int				**matrix;
	char			*map;
	char			*file_name;
	unsigned int	pixel_color;
	int				height;
	int				width;
	int				bits;
	int				fd;
	
	float			x;
	float			y;
	float			z;
	float			z1;
	int				win_width;
	int				win_height;
	double			angle;
	float			zoom;
	float			shift;
	int				is_iso;
}	t_map;


int		counter(char const *s, char c);
char	**ft_split(char const *s, char c);
void	free_str(char **str);
void	*ft_calloc(size_t count, size_t size);
int		close_the_window(void);
int		deal_key(int key, t_map *map);
int		ft_atoi(char *s);
void	ac(int ac);
float	absolutely(float i);
int		max(int x, int y);
void	russian_draw(float x, float y, float x1, float y1, t_map *map);
void	russian_roulette(t_map *map);
void	zoomed(float *x, float *y, float *x1, float *y1, t_map *map);
int		get_height(t_map *map);
int		get_width(t_map *map);
void	get_int_value_of_the_box(t_map *map);
unsigned int	fake_map(t_map *map);

#endif
