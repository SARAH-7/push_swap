/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:40:30 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/03 00:13:45 by sbakhit          ###   ########.fr       */
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

void	mech_turk_algo(t_stack_node **a, t_stack_node **b)
{
	int	i;
	// int	num;

	pb_func(a, b);
	pb_func(a, b);
	i = ft_lstsize(*a) - 3;
	printf("size %d\n", ft_lstsize(*a));
	while (i--)
	{
		if ((*b)->content != find_max(*b) && (*a)->content > (*b)->content && (*a)->content > (*b)->next->content)
			sb_func(b);
		pb_func(a, b);
		if ((*b)->content < (*b)->next->next->content)
			rrb_func(b);
	}
	// sort_three_func(a);
	// while (*b)
	// {
	// 	pa_func(b, a);
	// 	if (find_pos(*a, find_max(*a)) == ft_lstsize(*a)
	// 		&& find_pos(*a, find_pos(*a, find_max(*a)) < (*a)->content))
	// 	{
	// 		rra_func(a);
	// 		sa_func(a);
	// 		ra_func(a);
	// 		ra_func(a);
	// 	}
	// 	else if (find_pos(*a, find_min(*a)) == 2
	// 		&& find_min(*a) < (*a)->content && (*a)->content != find_max(*a) && (*a)->content < (*a)->next->next->content)
	// 		sa_func(a);
	// 	else if ((*a)->content == find_max(*a))
	// 		ra_func(a);
	// 	else
	// 	{
	// 		num = (*a)->content;
	// 		if (ft_lstsize(*a) % 2 == 0)
	// 		{
	// 			while ((*a)->next->content < num)
	// 			{
	// 				ra_func(a);
	// 				sa_func(a);
	// 			}
	// 			while (find_pos(*a, find_min(*a)) != 1)
	// 				rra_func(a);
	// 		}
	// 		else
	// 		{
	// 			while ((find_last_node(*a)->content) > num)
	// 			{
	// 				rra_func(a);
	// 				sa_func(a);
	// 			}
	// 			while (find_pos(*a, find_max(*a)) != ft_lstsize(*a))
	// 				rra_func(a);
	// 		}
	// 	}
	// }
}

void	not_sorting(t_stack_node **a, t_stack_node **b)
{
	if (ft_lstsize(*a) == 2)
		sa_func(a);
	else if (ft_lstsize(*a) == 3)
		sort_three_func(a);
	else if (ft_lstsize(*a) == 4)
		sort_four_func(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five_func(a, b);
	else
		mech_turk_algo(a, b);
}
