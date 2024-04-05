/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/05 22:27:16 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					flag_error;
	int					content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}			t_stack_node;

typedef struct s_instructions
{
	int					sa;
	int					sb;
	int					ss;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					total;
}			t_instructions;

int				main(int ac, char **av);

char			**ft_split(const char *s, char c);
int				ft_lstsize(t_stack_node *a);
t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node	ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
int				sorted_stack(t_stack_node *a);
void			not_sorting(t_stack_node **a, t_stack_node **b);
void			sa_func(t_stack_node **a);
void			sb_func(t_stack_node **b);
void			ss_func(t_stack_node **a, t_stack_node **b);
void			ra_func(t_stack_node **a);
void			rb_func(t_stack_node **b);
void			rr_func(t_stack_node **a, t_stack_node **b);
void			rra_func(t_stack_node **a);
void			rrb_func(t_stack_node **b);
void			rrr_func(t_stack_node **a, t_stack_node **b);
void			sort_three_func(t_stack_node **a);
void			sort_four_func(t_stack_node **a, t_stack_node **b);
void			sort_five_func(t_stack_node **a, t_stack_node **b);
void			mech_turk_algo(t_stack_node **a, t_stack_node **b);
void			pa_func(t_stack_node **a, t_stack_node **b);
void			pb_func(t_stack_node **b, t_stack_node **a);
int				find_min(t_stack_node *a);
int				find_max(t_stack_node *a);
int				find_pos(t_stack_node *a, int min);
t_stack_node	*find_last_node(t_stack_node *a);
t_stack_node	*find_prev_node(t_stack_node *a);

#endif