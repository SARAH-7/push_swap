/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:38:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 14:37:48 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_empty_b(t_stacks *stacks)
{
	stacks->head_b = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = NULL;
	printf("pb\n");
}

void	ft_last_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp_node;

	tmp_node = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_a->next = tmp_node;
	stacks->head_b = NULL;
	printf("pa\n");
}

void	pb_func(t_stacks *stacks)
{
	t_stack_b	*tmp_node;

	tmp_node = stacks->head_b;
	stacks->head_b = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp_node;
	printf("pb\n");
}

void	pa_func(t_stacks *stacks)
{
	t_stack_a	*tmp_node;

	tmp_node = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	stacks->head_a->next = tmp_node;
	printf("pa\n");
}
void	push_func(t_stacks *stacks, char ch)
{
	t_stack_b	*head_b;

	head_b = stacks->head_b;
	if (ch == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_last_push_a(stacks);
		else
			pa_func(stacks);
	}
	else if (ch == 'b')
	{
		if (head_b == NULL)
			ft_push_empty_b(stacks);
		else
			pb_func(stacks);
	}
}