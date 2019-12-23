NAME = fdf

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./inc/

LIB_DIR = ./libft/

SRC = main.c bresenham.c drawing.c move.c parsing.c read_file.c rotation.c shift.c zoom.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror -I /usr/local/include 

MLX_F = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(MLX_F) $(LIB_DIR)libft.a

$(LIB):
	make -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS) $< -o $@ -I $(INC_DIR)

clean:
	make -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean	
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

vpath %.c $(SRC_DIR)
