# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calypso <calypso@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/04/18 01:42:47 by calypso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	root/fdf_utils.c \
		root/errors.c \
		root/fdf_utils2.c\
		root/line_by_line.c \
		root/main.c \
		root/map_algorithm.c \
		root/window.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

FRAEMWORK = -framework OpenGL -framework Appkit -g
LIN = -lXext -lX11 -lm -ldl
FLAGS = -Wall -Wextra -Werror
LIBX = mlx/libmlx.a
SEG = -fsanitize=address
DIR = --no-print-directory
ERR = 2>/dev/null || true

.SILENT:

all:
	make $(DIR) -w -C ./mlx $(ERR)
	gcc $(SRC) $(FLAGS) $(LIBX) $(LIN) $(SEG) -o fdf
	
clean:
	make $(DIR) clean -C ./mlx $(ERR)

fclean: clean
	rm -rf fdf $(ERR)

com:
	./fdf maps/42.fdf

re: fclean all

.PHONY: all clean fclean com re
