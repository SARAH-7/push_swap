/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:39:02 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 14:37:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack_a *a)
{
	int	min;
	int	num;

	num = a->content;
	min = a->content;
	a = a->next;
	while (a != NULL)
	{
		if (a->content < min && a->content < num)
			min = a->content;
		a = a->next;
	}
	return (min);
}
int	find_min_b(t_stack_b *b)
{
	int	min;
	int	num;

	num = b->content;
	min = b->content;
	b = b->next;
	while (b != NULL)
	{
		if (b->content < min && b->content < num)
			min = b->content;
		b = b->next;
	}
	return (min);
}

int	find_max(t_stack_a *a)
{
	int	max;

	max = a->content;
	while (a != NULL)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
}
int	find_max_b(t_stack_b *b)
{
	int	max;

	max = b->content;
	while (b != NULL)
	{
		if (b->content > max)
			max = b->content;
		b = b->next;
	}
	return (max);
}

int	find_pos(t_stack_a *a, int min)
{
	int	index;

	index = 1;
	while (a != NULL)
	{
		if (a->content == min)
			return (index);
		a = a->next;
		index++;
	}
	return (0);
}
int	find_pos_b(t_stack_b *b, int min)
{
	int	index;

	index = 1;
	while (b != NULL)
	{
		if (b->content == min)
			return (index);
		b = b->next;
		index++;
	}
	return (0);
}

t_stack_a	*find_last_node(t_stack_a *a)
{
	t_stack_a	*num;

	num = a;
	while (a->next != NULL)
	{
		a = a->next;
		num = a;
	}
	return (num);
}

t_stack_a	*find_prev_node(t_stack_a *a)
{
	t_stack_a	*prev_node;

	prev_node = a;
	a = a->next;
	while (a->next != NULL)
	{
		if (a->next->content > (prev_node)->content)
		{
			(prev_node) = a;
			break ;
		}
		a = a->next;
	}
	return (prev_node);
}

void	get_top_stack_a(t_stacks stacks, t_stack_a *a, int i)
{
	int	size;

	stacks.moves->pb = 1;
	stacks.moves->ra = 0;
	stacks.moves->rra = 0;
	if (ft_lstsize(a) <= 1)
		return ;
	size = ft_lstsize(a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks.moves->rra = (size - i);
		else
			stacks.moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stacks.moves->rra = (size - i);
		else
			stacks.moves->ra = i;
	}
}

void	do_cheap_moves(t_stacks stacks)
{
	while (stacks.cheap->ra-- != 0)
		rotate_func(&stacks, 'a');
	while (stacks.cheap->rb-- != 0)
		rotate_func(&stacks, 'b');
	while (stacks.cheap->rr-- != 0)
		rotate_func(&stacks, 'r');
	while (stacks.cheap->rra-- != 0)
		rotate_func(&stacks, 'a');
	while (stacks.cheap->rrb-- != 0)
		rotate_func(&stacks, 'b');
	while (stacks.cheap->rrr-- != 0)
		rotate_func(&stacks, 'r');
	while (stacks.cheap->pb-- != 0)
		push_func(&stacks, 'b');
}