// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   train.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/10 18:38:16 by mervyilm          #+#    #+#             */
// /*   Updated: 2023/03/11 12:02:11 by mervyilm         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// /************************************ 3D **************************************/

// 			x' = (x - y) * cos(angle);
// 			y' = (x + y) * sin(angle) - z;
//			*x = (*x - *y)*sin(0.8);
//			*y = (*x + *y)*cos(0.8) - z;				
			
// /******************************* mlx usage **************************************/

// 			void	*mlx_ptr;
// 			void	*win_ptr;

// 			mlx_ptr = mlx_init();
// 			win_ptr = mlx_new_window(mlx_ptr, 400, 400, "mlx deneme");
// 			mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0x90e0ef);
			
// 			//This function allows user to deal with a key
// 			//Using this will allow writig on the terminal when pressed X
// 			mlx_key_hook(win_ptr, deal_key, (void *)0);

// 			mlx_loop(mlx_ptr);

// /********************************* deal_key **************************************/

// 			int deal_key(int key, void *param)

// /*********************************** Colors **************************************/

// 			blue = 0x90e0ef
// 			white = 0xffffff

// /********************************** framework ************************************/

// 			FRAMEWORK = -framework OpenGL -framework Appkit -g
// 			LNUX = -lXext -lX11  -lm -ldl
// 			LIBX = minilibx_macos/libmlx.a
//			FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit
//			-fsanitize=address


// /********************************** bresenham ************************************/

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;
	int zoom;
	
	zoom = 20;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	
	x *= zoom;
	y *= zoom;
	x1 *= zoom;
	y1 *= zoom;

	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	
	while((int)(x-x1) || (int)(y-y1))
	{
		mlx_pixel_put();
		x += x_step;
		y += y_step;
	}
}

// /********************************** draw ************************************/

void	draw(fdf *data)
{
	int x;
	int y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x+1, y, data);
			if (y < data->heigth - 1)
				bresenham(x, y, x, y+1, data);
			x++;
		}
		y++;
	}
}
			

	
	
	
	


