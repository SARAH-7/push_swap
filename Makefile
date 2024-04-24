# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 19:08:49 by sbakhit           #+#    #+#              #
#    Updated: 2024/04/24 14:23:08 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SOURCES = \
	ft_isdigit.c ft_split.c lists_funcs.c sorting_funcs.c push_funcs.c mech_funcs.c \
	swap_funcs.c rotate_funcs.c reverse_rotate_funcs.c mini_sorting.c cheapest_moves.c\
	ft_strjoin.c ft_strdup.c free_stack.c input_check.c ft_atoi.c check_doubles.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -ggdb3 -fsanitize=address
AR = ar
MAIN = push_swap.c

all: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o push_swap

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re