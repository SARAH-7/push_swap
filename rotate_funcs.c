/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 17:32:21 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_func(t_stack_node **a)
{
	t_stack_node	*first_node;
	int				temp;

	first_node = *a;
	while ((*a)->next != NULL)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
		*a = (*a)->next;
	}
	*a = first_node;
	printf("ra\n");
}

void	rb_func(t_stack_node **b)
{
	t_stack_node	*first_node;
	int				temp;

	first_node = *b;
	while ((*b)->next != NULL)
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
		*b = (*b)->next;
	}
	*b = first_node;
	printf("rb\n");
}

void	rr_func(t_stack_node **a, t_stack_node **b)
{
	ra_func(a);
	rb_func(b);
	printf("rr\n");
}
