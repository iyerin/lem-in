NAME = lem-in

HEADER = includes/*.h

LIB = libft/libft.a

ORIGINAL_LIST = main.c additional.c parser.c parser2.c
 
OBJ_LIST = $(ORIGINAL_LIST:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME)

%.o: %.c $(HEADER)
	@ $(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIB) $(OBJ_LIST)
	@ $(CC) $(CFLAGS) $(OBJ_LIST) $(LIB) -o $(NAME)

$(LIB):
	@ make -C libft/

clean:
	@ rm -f $(OBJ_LIST)
	@ make clean -C libft/

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/ 

re: fclean all
