# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calypso <calypso@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/03/26 01:25:37 by calypso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = root/fdf_utils.c \
	root/line_by_line.c \
	root/main.c \
	root/map_algorithm.c \
	root/window.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \


FRAEMWORK = -lmlx -lXext -lX11 
FLAGS = -Wall -Wextra -Werror
LIBX = mlx/libmlx.a

all:
	@make -C ./mlx
	@gcc $(SRC) $(FLAGS) $(LIBX) $(FRAEMWORK) -o fdf
	
clean:
	@make clean -C ./mlx

fclean: clean
	@rm -f fdf

re: fclean all

com:
	@./fdf maps/42.fdf

.PHONY: all clean fclean re
