/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/24 19:03:10 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct t_stack_a
{
	int					content;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					content;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct stack
{
	int				content;
	struct stack	*next;
	struct values	*values;
	struct moves	*moves;
	struct cheap	*cheap;
}				t_stack;

typedef struct values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

typedef struct moves
{
	int					total;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct cheap
{
	int					total;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;
char	**ps_split(const char *s, char c);
void	free_split(char **split_nums);
int		ps_atoi(const char *str, t_stack **a, char **split_nums);
int		main(int ac, char **av);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		isdigit_issign(int c);
int		pb_lstsize(t_stack *a);
int		pb_lstsize_b(t_stack *b);
t_stack	*pb_lstlast(t_stack *a);
t_stack	pb_lstadd_back(t_stack **lst, t_stack *new);
void	ft_rev_rotate(t_stack **b, char ch);
int		sorted_stack(t_stack *a);
t_stack	*not_sorting(t_stack **a, t_stack **b);
void	swap_op(t_stack **t);
void	ra_func(t_stack **a);
void	rb_func(t_stack **b);
void	rr_func(t_stack **a, t_stack **b);
void	rra_func(t_stack **a);
void	rrb_func(t_stack **b);
void	sort_three_func(t_stack **a, t_stack **b);
void	sort_four_func(t_stack **a, t_stack **b);
void	mech_turk_algo(t_stack **a, t_stack **b);
int		find_max(t_stack *a);
int		find_pos(t_stack *a, int min);
t_stack	*find_last_node(t_stack *a);
t_stack	*find_prev_node(t_stack *a);
void	node_of_cheapest_move(t_stack **a, t_stack **b,
			t_values *values, t_cheap *cheapest);
void	free_stack(t_stack **x);
int		is_num(char **split_nums);
void	check_for_doubles(t_stack *a);
void	ft_rotate_a(t_stack **a, int print);
void	ft_rotate_b(t_stack **b, int print);
void	ft_rev_rotate_a(t_stack **a, int print);
void	ft_rev_rotate_b(t_stack **b, int print);
void	push_func(t_stack **a, t_stack **b, char ch);
int		find_max_b(t_stack *b);
int		find_pos_b(t_stack *b, int min);
void	swap_func(t_stack **t, char ch);
int		stack_init(t_stack **a, char **split_nums);
void	check_min_a(t_stack **a);
void	check_max_a(t_stack **a);
void	check_max_min_b(t_stack **b, t_values *values);
void	check_double_moves(t_moves *a_moves, t_moves *b_moves);
void	do_cheap_moves(t_stack **a, t_stack **b, t_cheap *cheapest);
int		find_min(t_stack *a);
int		find_min_b(t_stack *b);
int		find_max(t_stack *a);
int		find_max_b(t_stack *b);
int		get_smallest_largest_b(t_stack **b, int num, t_values *values);
int		get_smallest_largest_a(t_stack **a, int num);
void	get_top_stack_a(t_stack **a, t_moves *a_moves, int num, int i);
void	get_top_stack_b(t_stack **b, t_moves *b_moves, int i);
void	moves_calculator(t_moves *a_moves, t_moves *b_moves,
			t_cheap *cheapest, int i);
void	new_max_or_min_stack_b(t_stack **b, t_moves *b_moves, t_values *values);
void	node_of_cheapest_move_b(t_stack **b);
void	rev_rotate_func(t_stack **a, t_stack **b, char ch);
void	rotate_func(t_stack **a, t_stack **b, char ch);
void	sort_stack_a(t_stack **a, t_stack **b,
			t_values *values, t_moves *a_moves);
void	pa_func(t_stack **a, t_stack **b);
void	pb_func(t_stack **a, t_stack **b);
void	check_double_moves(t_moves *a_moves, t_moves *b_moves);
void	moves_calculator(t_moves *a_moves, t_moves *b_moves,
			t_cheap *cheapest, int i);
void	move_max(t_stack **a, t_stack **b,
			t_values *values, t_moves *a_moves);
void	move_min(t_stack **a, t_stack **b,
			t_values *values, t_moves *a_moves);
#endif