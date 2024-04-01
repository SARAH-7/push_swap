/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:40:30 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 22:11:38 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack_node *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three_func(t_stack_node **a)
{
	if ((*a)->next->content < (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
	{
		ra_func(a);
	}
	if ((*a)->content > (*a)->next->content)
	{
		sa_func(a);
		printf("sa\n");
	}
	if ((*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
	{
		rra_func(a);
		printf("rra\n");
	}
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa_func(a);
		printf("sa\n");
		ra_func(a);
		printf("ra\n");
	}
}

void	sort_four_func(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	min;
	int	max;

	len = 0;
	min = 0;
	max = 0;
	pb_func(a, b);
	sort_three_func(a);
	len = ft_lstsize(*b);
	while (len--)
	{
		pa_func(b, a);
		min = find_min(*a);
		max = find_max(*a);
		if (find_pos(*a, max) == 1 && max == ft_lstsize(*a))
		{
			ra_func(a);
			printf("ra\n");
		}
		else if (find_pos(*a, max) == ft_lstsize(*a))
		{
			rra_func(a);
			printf("rra\n");
			sa_func(a);
			printf("sa\n");
			ra_func(a);
			printf("ra\n");
			ra_func(a);
			printf("ra\n");
		}
		else if (find_pos(*a, min) == 2)
		{
			sa_func(a);
			printf("sa\n");
		}
	}
}

void	mech_turk_algo(t_stack_node **a, t_stack_node **b)
{
	int	i;
	int	min;
	int	max;

	min = 0;
	// pb_func(a, b);
	// pb_func(a, b);
	sort_three_func(a);
	i = ft_lstsize(*b);
	while (i--)
	{
		pa_func(b, a);
		min = find_min(*a);
		max = find_max(*a);
		if (find_pos(*a, max) == ft_lstsize(*a) || max == ft_lstsize(*a))
		{
			ra_func(a);
			printf("ra\n");
		}
		else if (find_pos(*a, min) == 2)
		{
			sa_func(a);
			printf("sa\n");
		}
	}
}

void	not_sorting(t_stack_node **a, t_stack_node **b)
{
	if (ft_lstsize(*a) == 2)
		sa_func(a);
	else if (ft_lstsize(*a) == 3)
		sort_three_func(a);
	else if (ft_lstsize(*a) == 4)
		sort_four_func(a, b);
	else
		mech_turk_algo(a, b);
}
