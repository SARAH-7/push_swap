/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 06:47:08 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/20 06:56:51 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
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

int	find_min_b(t_stack *b)
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

int	find_max(t_stack *a)
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

int	find_max_b(t_stack *b)
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
