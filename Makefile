# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/04/14 16:18:14 by mervyilm         ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror
LIBX = mlx/libmlx.a
SEG = -fsanitize=address

.SILENT:

all:
	make -w -C ./mlx 2>/dev/null || true
	gcc $(SRC) $(FLAGS) $(LIBX) $(FRAEMWORK) $(SEG) -o fdf
	
clean:
	make clean -C ./mlx 2>/dev/null || true

fclean: clean
	rm -rf fdf 2>/dev/null || true

com:
	./fdf maps/42.fdf

re: fclean all

.PHONY: all clean fclean com re
