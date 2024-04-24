/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 14:31:27 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_func(t_stacks *stacks, t_stack_a *head_a, int print)
{
	t_stack_a	*tmp_node;
	int			i;
	int			size;

	size = ft_lstsize(head_a);
	tmp_node = head_a;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp_node;
	stacks->head_a = head_a;
	tmp_node = stacks->head_a;
	i = 0;
	while (i++ < size - 1)
		tmp_node = tmp_node->next;
	tmp_node->next = NULL;
	if (print != 0)
		printf("rra\n");
}

void	rrb_func(t_stacks *stacks, t_stack_b *head_b, int print)
{
	t_stack_b	*tmp_node;
	int			i;
	int			size;

	size = ft_lstsize_b(head_b);
	tmp_node = head_b;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp_node;
	stacks->head_b = head_b;
	tmp_node = stacks->head_b;
	i = 0;
	while (i++ < size - 1)
		tmp_node = tmp_node->next;
	tmp_node->next = NULL;
	if (print != 0)
		printf("rrb\n");
}

void	rev_rotate_func(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		rra_func(stacks, stacks->head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		rrb_func(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		rra_func(stacks, stacks->head_a, 0);
		rrb_func(stacks, head_b, 0);
		printf("rrr\n");
	}
}