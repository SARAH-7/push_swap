/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:02:10 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 13:41:36 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_calculator(t_stacks stacks, int i)
{
	stacks.moves->total = stacks.moves->pb + stacks.moves->ra
		+ stacks.moves->rb + stacks.moves->rr + stacks.moves->rra
		+ stacks.moves->rrb + stacks.moves->rrr;
	if (i == 1 || (stacks.cheap->total > stacks.moves->total))
	{
		stacks.cheap->total = stacks.moves->total;
		stacks.cheap->pb = stacks.moves->pb;
		stacks.cheap->ra = stacks.moves->ra;
		stacks.cheap->rb = stacks.moves->rb;
		stacks.cheap->rr = stacks.moves->rr;
		stacks.cheap->rra = stacks.moves->rra;
		stacks.cheap->rrb = stacks.moves->rrb;
		stacks.cheap->rrr = stacks.moves->rrr;
	}
}

void	check_double_moves(t_stacks stacks)
{
	stacks.moves->rr = 0;
	stacks.moves->rrr = 0;
	while (stacks.moves->ra != 0 && stacks.moves->rb != 0)
	{
		stacks.moves->ra--;
		stacks.moves->rb--;
		stacks.moves->rr++;
	}
	while (stacks.moves->rra != 0 && stacks.moves->rrb != 0)
	{
		stacks.moves->rra--;
		stacks.moves->rrb--;
		stacks.moves->rrr++;
	}
}
void	new_max_or_min_stack_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->content == stacks->values->max_b)
		return ;
	i = find_pos_b(stacks->head_b, stacks->values->max_b);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	new_num_in_stack_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->content == num)
		return ;
	i = find_pos_b(stacks->head_b, num);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	node_of_cheapest_move(t_stacks stacks)
{
	int			i;
	int			size;

	// head_a = stacks->head_a;
	size = ft_lstsize(stacks.head_a);
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(stacks, stacks.head_a, i - 1);
		if (stacks.head_a->content > find_max_b(stacks.head_b) || 
			stacks.head_a->content < find_min_b(stacks.head_b))
				new_max_or_min_stack_b(&stacks);
		else
			new_num_in_stack_b(&stacks, stacks.head_a->content);
		check_double_moves(stacks);
		moves_calculator(stacks, i);
		stacks.head_a = stacks.head_a->next;
	}
}
