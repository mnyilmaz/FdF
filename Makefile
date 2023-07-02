# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/07/03 01:51:46 by mervenuryil      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	root/fdf_utils.c \
		root/fdf_utils2.c\
		root/errors.c \
		root/color.c \
		root/reading_the_map.c \
		root/main.c \
		root/map_algorithm.c \
		root/window.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

FRAEMWORK = -framework OpenGL -framework Appkit -g
FLAGS = -Wall -Wextra -Werror
LIBX = mlx/libmlx.a
SEG = -fsanitize=address
DIR = --no-print-directory
ERR = 2>/dev/null || true
G = \033[1;42m
R = \033[1;41m
B = \033[1;44m
END = \033[0m
MAP = eco.fdf

.SILENT:

all:
	make $(DIR) -w -C ./mlx $(ERR)
	gcc $(SRC) $(FLAGS) $(LIBX) $(FRAEMWORK) $(SEG) -o fdf
	echo "$(G)Compiled - to run enter 'make run'$(END)"
	echo "$(R)Default map is eco, to change organize the Makefile$(END)"

clean:
	make $(DIR) clean -C ./mlx $(ERR)

fclean: clean
	rm -rf fdf $(ERR)

run:
	echo "$(B)okh eshivar$(END)"
	./fdf maps/$(MAP)

re: fclean all

.PHONY: all clean fclean run re
