NAME = CUB3D
CC = cc
SRC = main.c \
	 ./get_next_line/get_next_line.c \
	 ./parsing/return_map.c
FLAGS = -Wall -Wextra -Werror
FLA = -lmlx -framework OpenGL -framework AppKit -g
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC) $(FLAGS) $(FLA) $(SRC) $(ARG) $(NAME) ./libft/libft.a

clean :
	cd libft && rm -rf *.o
	rm -rf CUB3D.dSYM
	rm -f $(NAME)

fclean : clean

re: fclean all