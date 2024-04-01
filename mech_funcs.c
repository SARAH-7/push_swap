/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mech_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:39:02 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 23:14:03 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack_node *a)
{
	int	min;
	int	num;

	num = a->content;
	min = a->content;
	while (a->next != NULL)
	{
		if (a->content < min && a->content < num)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int	find_max(t_stack_node *a)
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

int	find_pos(t_stack_node *a, int min)
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

t_stack_node	*find_last_node(t_stack_node *a)
{
	t_stack_node	*num;

	num = a;
	while (a->next != NULL)
	{
		a = a->next;
		num = a;
	}
	return (num);
}
