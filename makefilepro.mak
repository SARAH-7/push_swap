
# variables

NAME = push_swap

LIB = libpush_swap.a

SOURCES = \
	ft_split.c lists_funcs.c sorting_funcs.c push_funcs.c mech_funcs.c \
	swap_funcs.c rotate_funcs.c reverse_rotate_funcs.c mini_sorting.c

MAIN = push_swap.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

ARGS = "38487 9872875 1387 23437 48949 5907 23984937"

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(MAIN) -o $@

$(LIB): $(OBJECTS)
	$(AR) -rcs $@ $?

run: all
	./$(NAME) $(ARGS) 

%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
