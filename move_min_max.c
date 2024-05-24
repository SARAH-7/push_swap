/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 07:02:18 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/21 11:13:25 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max(t_stack **a, t_stack **b,
		t_values *values, t_moves *a_moves)
{
	int	position;
	int	size;

	a_moves->ra = 0;
	a_moves->rra = 0;
	if (pb_lstlast(*a)->content != values->max_a)
	{
		size = pb_lstsize(*a);
		position = find_pos(*a, values->max_a);
		if (position > size / 2)
			a_moves->rra = (size - position);
		else
			a_moves->ra = position + 1;
		while (a_moves->ra-- > 0)
			rotate_func(a, b, 'a');
		while (a_moves->rra-- > 0)
			rev_rotate_func(a, b, 'a');
	}
	pa_func(a, b);
	ft_printf("pa\n");
}

void	move_min(t_stack **a, t_stack **b,
		t_values *values, t_moves *a_moves)
{
	int	position;
	int	size;

	a_moves->ra = 0;
	a_moves->rra = 0;
	if ((*a)->content != values->min_a)
	{
		position = find_pos(*a, values->min_a);
		size = pb_lstsize(*a);
		if (position + 1 > size / 2)
			a_moves->rra = (size - position);
		else
			a_moves->ra = position;
		while (a_moves->ra-- > 0)
			rotate_func(a, b, 'a');
		while (a_moves->rra-- > 0)
			rev_rotate_func(a, b, 'a');
	}
	pa_func(a, b);
	ft_printf("pa\n");
}