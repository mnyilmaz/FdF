# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:08:40 by mervyilm          #+#    #+#              #
#    Updated: 2023/03/18 13:23:57 by mervyilm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)


CC = gcc
FRAMEWORK = -framework OpenGL -framework Appkit
FLAGS = -Wextra -Wall -Werror
LIBX = minilibx_macos/libmlx.a


com:  $(OBJ)
	@$(CC) $(FLAGS) $(FRAMEWORK) $(OBJ) get_next_line/*c $(LIBX) -o fdf
	@./fdf maps/test_maps/10-70.fdf

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf fdf
	rm -rf fdf.DSYM
	
re: fclean com

.PHONY: all clean fclean re com
