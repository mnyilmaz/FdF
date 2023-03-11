# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/03/11 17:27:54 by mervyilm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a



CC = gcc
FRAMEWORK = -framework OpenGL -framework Appkit -g
LIBX = minilibx_macos/libmlx.a


com: 
	@$(CC) main.c $(LIBX) $(FRAMEWORK) -o fdf -g
	@./fdf

.PHONY: all clean fclean re
