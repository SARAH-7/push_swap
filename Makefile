# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 19:08:49 by sbakhit           #+#    #+#              #
#    Updated: 2024/05/24 19:02:55 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
SOURCES = \
	isdigit_issign.c lists_funcs.c sorting_funcs.c push_funcs.c mech_funcs.c \
	swap_funcs.c rotate_funcs.c reverse_rotate_funcs.c mini_sorting.c cheapest_moves.c \
	ft_strjoin.c ft_strdup.c free_stack.c input_check.c check_doubles.c \
	sort_stack_a.c moves_funcs.c min_max_func.c move_min_max.c ps_atoi.c ps_split.c\

BSOURCES = \
	checker.c isdigit_issign.c lists_funcs.c sorting_funcs.c push_funcs.c mech_funcs.c \
	swap_funcs.c rotate_funcs.c reverse_rotate_funcs.c mini_sorting.c cheapest_moves.c \
	ft_strjoin.c ft_strdup.c free_stack.c input_check.c check_doubles.c \
	sort_stack_a.c moves_funcs.c min_max_func.c move_min_max.c get_next_line.c ps_split.c\
	get_next_line_utils.c ps_atoi.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar
NAME = push_swap
MAIN = push_swap.c

BONUS_NAME = checker

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C libft all

$(FT_PRINTF):
	@$(MAKE) -C ft_printf all

$(NAME): $(MAIN) $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(MAIN) $(OBJECTS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

bonus: $(BONUS_NAME)
$(BONUS_NAME): $(BOBJECTS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(BOBJECTS) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<


clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re


