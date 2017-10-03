NAME = fdf

SRC =  events_1.c events_2.c input_handler_1.c input_handler_2.c line.c main.c

FLAG = gcc -c -g -Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

LIBFT = ./libft/libft.a

MLX = -L minilibx_macos

all: $(NAME)

$(NAME):
	cd ./libft && make && cd ..
	$(FLAG) $(SRC)
	gcc $(OBJ) -o $(NAME) $(LIBFT) $(MLX) -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && make fclean 
	
re: fclean all
	cd libft && make re
