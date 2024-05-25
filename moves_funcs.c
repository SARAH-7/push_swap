/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 06:54:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 03:25:39 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_calculator(t_moves *a_moves, t_moves *b_moves,
	t_cheap *cheapest, int i)
{
	a_moves->total = a_moves->pb + a_moves->ra
		+ b_moves->rb + a_moves->rr + a_moves->rra
		+ b_moves->rrb + a_moves->rrr;
	if (i == 1 || a_moves->total < cheapest->total)
	{
		cheapest->total = a_moves->total;
		cheapest->pb = a_moves->pb;
		cheapest->ra = a_moves->ra;
		cheapest->rb = b_moves->rb;
		cheapest->rr = a_moves->rr;
		cheapest->rra = a_moves->rra;
		cheapest->rrb = b_moves->rrb;
		cheapest->rrr = a_moves->rrr;
	}
}

void	check_double_moves(t_moves *a_moves, t_moves *b_moves)
{
	a_moves->rr = 0;
	a_moves->rrr = 0;
	while (a_moves->ra != 0 && b_moves->rb != 0)
	{
		a_moves->ra--;
		b_moves->rb--;
		a_moves->rr++;
	}
	while (a_moves->rra != 0 && b_moves->rrb != 0)
	{
		a_moves->rra--;
		b_moves->rrb--;
		a_moves->rrr++;
	}
}

void	do_cheap_moves(t_stack **a, t_stack **b, t_cheap *cheapest)
{
	while (cheapest->ra-- != 0)
		rotate_func(a, b, 'a');
	while (cheapest->rb-- != 0)
		rotate_func(a, b, 'b');
	while (cheapest->rr-- != 0)
		rotate_func(a, b, 'r');
	while (cheapest->rra-- != 0)
		rev_rotate_func(a, b, 'a');
	while (cheapest->rrb-- != 0)
		rev_rotate_func(a, b, 'b');
	while (cheapest->rrr-- != 0)
		rev_rotate_func(a, b, 'r');
	while (cheapest->pb-- != 0)
	{
		pb_func(a, b);
		ft_printf("pb\n");
	}
}
