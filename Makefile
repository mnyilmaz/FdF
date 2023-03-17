# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/03/17 15:32:45 by mervyilm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)


CC = gcc
FRAMEWORK = -Wextra -Wall -Werror -framework OpenGL -framework Appkit -fsanitize=address -g
LIBX = minilibx_macos/libmlx.a


com:  $(OBJ)
	@$(CC) $(OBJ) get_next_line/*c $(LIBX) $(FRAMEWORK) -o fdf
	@./fdf maps/test_maps/t1.fdf

.PHONY: all clean fclean re
