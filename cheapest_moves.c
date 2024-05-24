/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:02:10 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/22 19:33:54 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_max_or_min_stack_b(t_stack **b, t_moves *b_moves, t_values *values)
{
	int	i;
	int	size;

	b_moves->rb = 0;
	b_moves->rrb = 0;
	i = find_pos_b(*b, values->max_b);
	size = pb_lstsize_b(*b);
	if (i == 0)
		return ;
	else
	{
		if (i > size / 2)
			b_moves->rrb = size - i;
		else
			b_moves->rb = i;
	}
}

int	get_smallest_largest_b(t_stack **b, int num, t_values *values)
{
	t_stack	*temp;
	int		smallest_largest;
	int		max_b;

	temp = *b;
	max_b = values->max_b;
	smallest_largest = INT_MIN;
	while (temp != NULL)
	{
		if (smallest_largest < temp->content && temp->content < num
			&& temp->content != max_b)
			smallest_largest = temp->content;
		temp = temp->next;
	}
	return (smallest_largest);
}

void	new_num_in_stack_b(t_stack **b, t_moves *b_moves,
	int target_num, t_values *values)
{
	int	i;
	int	size;
	int	num;

	b_moves->rb = 0;
	b_moves->rrb = 0;
	size = pb_lstsize_b(*b);
	num = get_smallest_largest_b(b, target_num, values);
	i = find_pos_b(*b, num);
	if (i == 0)
		return ;
	if (i + 1 > size / 2)
		b_moves->rrb = size - i;
	else
		b_moves->rb = i;
}

void	node_of_cheapest_move(t_stack **a, t_stack **b,
t_values *values, t_cheap *cheapest)
{
	t_stack	*temp;
	t_moves	*a_moves;
	t_moves	*b_moves;
	int		i;
	int		size;

	temp = *a;
	i = 0;
	a_moves = malloc(sizeof(t_moves));
	b_moves = malloc(sizeof(t_moves));
	size = pb_lstsize(*a);
	while (i++ < size)
	{
		get_top_stack_a(a, a_moves, temp->content, i - 1);
		if (temp->content > values->max_b
			|| temp->content < values->min_b)
			new_max_or_min_stack_b(b, b_moves, values);
		else
			new_num_in_stack_b(b, b_moves, temp->content, values);
		check_double_moves(a_moves, b_moves);
		moves_calculator(a_moves, b_moves, cheapest, i);
		temp = temp->next;
	}
	free(a_moves);
	free(b_moves);
}
