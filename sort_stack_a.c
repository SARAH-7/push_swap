/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:51:57 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/21 11:13:56 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min_a(t_stack **a, t_values *values)
{
	t_stack	*temp;
	int		max_value;
	int		min_value;

	if (*a == NULL)
		return ;
	temp = *a;
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
	values->min_a = min_value;
	values->max_a = max_value;
}

int	get_smallest_largest_a(t_stack **a, int num)
{
	t_stack	*temp;
	int		smallest_largest;

	temp = *a;
	smallest_largest = INT_MAX;
	while (temp != NULL)
	{
		if (smallest_largest > temp->content && temp->content > num)
			smallest_largest = temp->content;
		temp = temp->next;
	}
	return (smallest_largest);
}

void	find_new_num_a(t_stack **a, t_stack **b,
		int num, t_moves *a_moves)
{
	int	position;
	int	size;
	int	nbr;

	a_moves->ra = 0;
	a_moves->rra = 0;
	size = pb_lstsize(*a);
	nbr = get_smallest_largest_a(a, num);
	position = find_pos(*a, nbr);
	if ((*a)->content != nbr)
	{
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

void	last_sort(t_stack **a, t_stack **b,
		t_values *values, t_moves *a_moves)
{
	int	size;
	int	position;

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
}

void	sort_stack_a(t_stack **a, t_stack **b, t_values *values,
		t_moves *a_moves)
{
	values->max_a = 0;
	values->min_a = 0;
	while ((*b) != NULL)
	{
		find_max_min_a(a, values);
		if ((*b)->content > values->max_a)
			move_max(a, b, values, a_moves);
		else if ((*b)->content < values->min_a)
			move_min(a, b, values, a_moves);
		else
			find_new_num_a(a, b, (*b)->content, a_moves);
	}
	find_max_min_a(a, values);
	last_sort(a, b, values, a_moves);
	not_sorting(a, b);
}
