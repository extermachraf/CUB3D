NAME = CUB3D
CC = cc
SRC = main.c \
	 ./get_next_line/get_next_line.c \
	 ./parsing/return_map.c \
	 ./parsing/parse_outils.c \
	 ./parsing/lexer.c \
	 ./parsing/pars_outils1.c \
	 ./parsing/take_map.c \
	 ./parsing/linked_outils.c \
	 ./parsing/check_map.c \
	 ./parsing/check_map1.c
FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLA = -lmlx -framework OpenGL -framework AppKit -g
ARG = -o
#-fsanitize=address
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