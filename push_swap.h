/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 17:23:36 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

typedef struct t_stacks
{
	struct t_stack_a	*head_a;
	struct t_stack_b	*head_b;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_cheap		*cheap;
}						t_stacks;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

typedef struct t_moves
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

typedef struct t_cheap
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

int				main(int ac, char **av);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isdigit_issign(int c);
char			**ft_split(const char *s, char c);
int				ft_lstsize(t_stack_a *a);
t_stack_a		*ft_lstlast(t_stack_a *lst);
t_stack_a		ft_lstadd_back(t_stack_a **lst, t_stack_a *new);
int				sorted_stack(t_stack_a *a);
void			not_sorting(t_stacks *stacks);
void			sa_func(t_stack_a *a);
void			sb_func(t_stack_b *b);
void			ss_func(t_stack_a *a, t_stack_b *b);
void			ra_func(t_stacks *stacks, t_stack_a *head_a, int print);
void			rb_func(t_stacks *stacks, t_stack_b *head_b, int print);
void			rr_func(t_stack_a *a, t_stack_b *b);
void			rra_func(t_stacks *stacks, t_stack_a *head_a, int print);
void			rrb_func(t_stacks *stacks, t_stack_b *head_b, int print);
void			rev_rotate_func(t_stacks *stacks, char ch);
void			sort_three_func(t_stacks *stacks);
void			sort_four_func(t_stacks *stacks);
void			sort_five_func(t_stacks *stacks);
void			mech_turk_algo(t_stacks *stacks);
void			pa_func(t_stacks *stacks);
void			pb_func(t_stacks *stacks);
int				find_min(t_stack_a *a);
int				find_max(t_stack_a *a);
int				find_pos(t_stack_a *a, int min);
t_stack_a		*find_last_node(t_stack_a *a);
t_stack_a		*find_prev_node(t_stack_a *a);
void			moves_calculator(t_stacks stacks, int i);
void			node_of_cheapest_move(t_stacks stacks);
void			free_stacks(t_stacks *stacks);
int				is_num(char **split_nums);
int				ft_atoi(const char *str);
void			check_for_doubles(t_stack_a *a);
void			do_cheap_moves(t_stacks stacks);
void			ft_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void			ft_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);
void			rotate_func(t_stacks *stacks, char ch);
void			ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void			ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);
void			ft_rev_rotate(t_stacks *stacks, char ch);
void			push_func(t_stacks *stacks, char ch);
int				ft_lstsize_b(t_stack_b *b);
int				find_max_b(t_stack_b *b);
int				find_min_b(t_stack_b *b);
void			get_top_stack_a(t_stacks stacks, t_stack_a *a, int i);
int				find_pos_b(t_stack_b *b, int min);

#endif