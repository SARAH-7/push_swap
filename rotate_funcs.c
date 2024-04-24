/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 14:33:19 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_func(t_stacks *stacks, t_stack_a *head_a, int print)
{
	t_stack_a	*tmp_head;

	tmp_head = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp_head;
	tmp_head->next = NULL;
	if (print != 0)
		printf("ra\n");
}

void	rb_func(t_stacks *stacks, t_stack_b *head_b, int print)
{
	t_stack_b	*tmp_head;

	tmp_head = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp_head;
	tmp_head->next = NULL;
	if (print != 0)
		printf("rb\n");
}

void	rotate_func(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ra_func(stacks, stacks->head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		rb_func(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		ra_func(stacks, stacks->head_a, 0);
		rb_func(stacks, head_b, 0);
		printf("rr\n");
	}
}