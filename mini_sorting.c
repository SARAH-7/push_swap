/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:36:09 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/02 19:44:47 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_func(t_stack_node **a)
{
	if ((*a)->next->content < (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
		ra_func(a);
	if ((*a)->content > (*a)->next->content)
		sa_func(a);
	if ((*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
		rra_func(a);
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa_func(a);
		ra_func(a);
	}
}

void	sort_four_func(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = 0;
	pb_func(a, b);
	sort_three_func(a);
	len = ft_lstsize(*b);
	while (len--)
	{
		pa_func(b, a);
		if (find_pos(*a, find_max(*a)) == 1 && find_max(*a) == ft_lstsize(*a))
			ra_func(a);
		else if (find_pos(*a, find_max(*a)) == ft_lstsize(*a))
		{
			rra_func(a);
			sa_func(a);
			ra_func(a);
			ra_func(a);
		}
		else if (find_pos(*a, find_min(*a)) == 2)
			sa_func(a);
	}
}

void	sort_five_func(t_stack_node **a, t_stack_node **b)
{
	int	i;

	pb_func(a, b);
	pb_func(a, b);
	sort_three_func(a);
	i = ft_lstsize(*b);
	while (i--)
	{
		pa_func(b, a);
		if (find_pos(*a, find_max(*a)) == ft_lstsize(*a)
			&& (*a)->next->next->content < (*a)->content)
		{
			rra_func(a);
			sa_func(a);
			ra_func(a);
			ra_func(a);
		}
		else if (find_pos(*a, find_min(*a)) == 2
			&& find_min(*a) < (*a)->content && (*a)->content != find_max(*a))
			sa_func(a);
		else if (find_max(*a) == ft_lstsize(*a)
			|| (*a)->content == find_max(*a))
			ra_func(a);
	}
}
