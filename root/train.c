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
