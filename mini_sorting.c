/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:36:09 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/24 18:08:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_func(t_stack **a, t_stack **b)
{
	if ((*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
		rev_rotate_func(a, b, 'a');
	if ((*a)->next->content < (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
		rotate_func(a, b, 'a');
	if ((*a)->content > (*a)->next->content)
		swap_func(a, 'a');
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		swap_func(a, 'a');
		rotate_func(a, b, 'a');
	}
}

void	sort_four_func(t_stack **a, t_stack **b)
{
	pb_func(a, b);
	ft_printf("pb\n");
	sort_three_func(a, b);
	pa_func(a, b);
	ft_printf("pa\n");
	if (find_min(*a) != (*a)->content)
	{
		if (find_pos(*a, find_max(*a)) == 1 && find_max(*a) == pb_lstsize(*a))
			rotate_func(a, b, 'a');
		else if (find_pos(*a, find_max(*a)) == pb_lstsize(*a))
		{
			rev_rotate_func(a, b, 'a');
			swap_func(a, 'a');
			rotate_func(a, b, 'a');
			rotate_func(a, b, 'a');
		}
		else if (find_pos(*a, find_min(*a)) == 2)
			swap_func(a, 'a');
	}
}
