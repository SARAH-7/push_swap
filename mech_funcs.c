/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:39:02 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/28 15:21:51 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack *a, int num)
{
	t_stack	*temp;
	int		size;
	int		i;

	i = 0;
	temp = a;
	size = pb_lstsize(a);
	while (i < size)
	{
		if (temp->content == num)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_pos_b(t_stack *b, int num)
{
	t_stack	*temp;
	int		size;
	int		i;

	i = 0;
	temp = b;
	size = pb_lstsize_b(b);
	while (i < size)
	{
		if (temp->content == num)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack	*find_last_node(t_stack *a)
{
	t_stack	*num;

	num = a;
	while (a->next != NULL)
	{
		a = a->next;
		num = a;
	}
	return (num);
}

t_stack	*find_prev_node(t_stack *a)
{
	t_stack	*prev_node;
	t_stack	*current;
	int		target;

	if (a == NULL || a->next == NULL)
		return (NULL);
	prev_node = a->next;
	current = a->next;
	target = a->content - 1;
	while (current != NULL)
	{
		if (current->content <= target && current->content > prev_node->content)
		{
			prev_node = current;
			if (current->content == target)
				break ;
		}
		current = current->next;
	}
	return (prev_node);
}

void	get_top_stack_a(t_stack **a, t_moves *a_moves, int num, int i)
{
	int	size;

	a_moves->pb = 1;
	a_moves->ra = 0;
	a_moves->rra = 0;
	if ((*a)->content == num)
		return ;
	size = pb_lstsize(*a);
	if (i + 1 > size / 2)
		a_moves->rra = (size - i);
	else
		a_moves->ra = i;
}
