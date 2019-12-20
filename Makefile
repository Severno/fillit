NAME = fillit
FILLIT_SRC = map.c read.c solver.c tetramino.c validation.c fillit.c
FILLIT_OBJ = map.o read.o solver.o tetramino.o validation.o fillit.o
FILLIT_INC = fillit.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror
LIB_HEADER = ../libft/libft.h
OBJ = $(subst .c,.o,$(FILLIT_SRC))

.PHONY: all clean fclean re

%.o: %.c $(LIB_HEADER)
	gcc -Wall -Wextra -Werror -I $(LIB_HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	gcc $(FLAGS) $(FILLIT_OBJ) -L. libft/libft.a -o $(NAME)

clean:
	/bin/rm -f $(FILLIT_OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: clean fclean all
