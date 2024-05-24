/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:40:30 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/22 23:36:11 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	check_max_min_b(t_stack **b, t_values *values)
{
	t_stack			*temp;
	int				max_value;
	int				min_value;

	if (*b == NULL)
		return ;
	temp = *b;
	max_value = temp->content;
	min_value = temp->content;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content > max_value)
			max_value = temp->content;
		else if (min_value > temp->content)
			min_value = temp->content;
	}
	values->min_b = min_value;
	values->max_b = max_value;
}

void	mech_turk_algo(t_stack **a, t_stack **b)
{
	t_values	*values;
	t_moves		*a_moves;
	t_cheap		*cheapest;

	a_moves = malloc(sizeof(t_moves));
	cheapest = malloc(sizeof(t_cheap));
	values = malloc(sizeof(t_values));
	values->max_b = 0;
	values->min_b = 0;
	pb_func(a, b);
	ft_printf("pb\n");
	pb_func(a, b);
	ft_printf("pb\n");
	while (pb_lstsize(*a) != 3)
	{
		check_max_min_b(b, values);
		node_of_cheapest_move(a, b, values, cheapest);
		do_cheap_moves(a, b, cheapest);
	}
	sort_three_func(a, b);
	sort_stack_a(a, b, values, a_moves);
	free(values);
	free(a_moves);
	free(cheapest);
}

t_stack	*not_sorting(t_stack **a, t_stack **b)
{
	if (!a || sorted_stack(*a))
		return (NULL);
	if (pb_lstsize(*a) == 2)
		swap_func(a, 'a');
	else if (pb_lstsize(*a) == 3)
		sort_three_func(a, b);
	else if (pb_lstsize(*a) == 4)
		sort_four_func(a, b);
	else
		mech_turk_algo(a, b);
	return (*a);
}