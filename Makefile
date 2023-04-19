# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/04/19 15:24:31 by mervyilm         ###   ########.fr        #
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
G = \033[1;42m
R = \033[1;41m
B = \033[1;44m
END = \033[0m
MAP = 42.fdf

.SILENT:

all:
	make $(DIR) -w -C ./mlx $(ERR)
	gcc $(SRC) $(FLAGS) $(LIBX) $(FRAEMWORK) $(SEG) -o fdf
	echo "$(G)Compiled - to run enter 'make run'$(END)"
	echo "$(R)Default map is 42, to change enter the Makefile$(END)"

clean:
	make $(DIR) clean -C ./mlx $(ERR)

fclean: clean
	rm -rf fdf $(ERR)

run:
	echo "$(B)okh eshivar$(END)"
	./fdf maps/$(MAP)

re: fclean all

.PHONY: all clean fclean run re
