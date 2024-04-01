/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 17:25:38 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_func(t_stack_node **a)
{
	t_stack_node	*second_last_node;
	t_stack_node	*last_node;

	last_node = *a;
	second_last_node = NULL;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *a;
	*a = last_node;
	printf("rra\n");
}

void	rrb_func(t_stack_node **b)
{
	t_stack_node	*second_last_node;
	t_stack_node	*last_node;

	last_node = *b;
	second_last_node = NULL;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *b;
	*b = last_node;
	printf("rrb\n");
}

void	rrr_func(t_stack_node **a, t_stack_node **b)
{
	rra_func(a);
	rrb_func(b);
	printf("rrr\n");
}
