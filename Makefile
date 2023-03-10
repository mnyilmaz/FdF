
CC = gcc
FRAMEWORK = -framework OpenGL -framework Appkit -g
LIBX = minilibx_macos/libmlx.a

com: 
	@$(CC) main.c $(LIBX) $(FRAMEWORK) -o main
	@./main

.PHONY: com