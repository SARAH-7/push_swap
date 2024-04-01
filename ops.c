/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:38:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 17:32:36 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_func(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	if (!(*a) || !b)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->content = (*a)->content;
	new_node->next = *b;
	*b = new_node;
	temp = (*a);
	(*a) = (*a)->next;
	free(temp);
	printf("pb\n");
}

void	pa_func(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	if (!(*a) || !b)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->content = (*b)->content;
	new_node->next = *a;
	*a = new_node;
	temp = (*b);
	(*b) = (*b)->next;
	free(temp);
	printf("pa\n");
}
