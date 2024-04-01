/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 18:11:09 by sbakhit          ###   ########.fr       */
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
}			t_stack_node;

int				main(int ac, char **av);

char			**ft_split(const char *s, char c);
int				ft_lstsize(t_stack_node *a);
t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node	ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
int				sorted_stack(t_stack_node *a);
void			not_sorting(t_stack_node **a, t_stack_node **b);
void			sa_func(t_stack_node **a);
void			sb_func(t_stack_node **b);
void			ra_func(t_stack_node **a);
void			rra_func(t_stack_node **a);
void			rra_func(t_stack_node **a);
void			sort_three_func(t_stack_node **a);
void			sort_four_func(t_stack_node **a, t_stack_node **b);
void			mech_turk_algo(t_stack_node **a, t_stack_node **b);
void			pa_func(t_stack_node **a, t_stack_node **b);
void			pb_func(t_stack_node **b, t_stack_node **a);
int				find_min(t_stack_node *a);
int				find_max(t_stack_node *a);
int				find_pos(t_stack_node *a, int min);
t_stack_node	*find_last_node(t_stack_node *a);

#endif