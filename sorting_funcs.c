/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:40:30 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 17:35:54 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack_a *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	mech_turk_algo(t_stacks *stacks)
{
	int				num;
	int				prev;
	struct t_moves	*moves;
	struct t_cheap	*cheap;
	t_values		*values;

	moves = malloc(sizeof(t_moves));
	stacks->moves = moves;
	cheap = malloc(sizeof(t_cheap));
	stacks->cheap = cheap;
	values = malloc(sizeof(t_values));
	stacks->values = values;

	pb_func(stacks);
	pb_func(stacks);
	while (ft_lstsize(stacks->head_a) != 3)
	{
		node_of_cheapest_move(*stacks);
		do_cheap_moves(*stacks);
	}
	sort_three_func(stacks);
	while (ft_lstsize(stacks->head_a) != 0)
	{
		pa_func(stacks);
		if ((stacks->head_a)->content != find_min(stacks->head_a))
		{
			
			prev = find_prev_node(stacks->head_a)->content;
			if (find_max(stacks->head_a) == find_last_node(stacks->head_a)->content
				&& prev < (stacks->head_a)->content)
			{
				while (find_last_node(stacks->head_a)->content != prev)
				{
					rev_rotate_func(stacks, 'a');
					sa_func(stacks->head_a);
				}
				while (find_pos(stacks->head_a, find_max(stacks->head_a)) != ft_lstsize(stacks->head_a))
					rotate_func(stacks, 'a');
			}
			else if (find_pos(stacks->head_a, find_min(stacks->head_a)) == 2
				&& find_min(stacks->head_a) < (stacks->head_a)->content && (stacks->head_a)->content != find_max(stacks->head_a)
				&& (stacks->head_a)->content < (stacks->head_a)->next->next->content)
				sa_func(stacks->head_a);
			else if ((stacks->head_a)->content == find_max(stacks->head_a))
				rotate_func(stacks, 'a');
			else
			{
				num = (stacks->head_a)->content;
				if (find_pos(stacks->head_a, prev) < ft_lstsize(stacks->head_a) / 2)
				{
					while ((stacks->head_a)->content <= num)
					{
						rotate_func(stacks, 'a');
						sa_func(stacks->head_a);
						(stacks->head_a) = (stacks->head_a)->next;
					}
					while ((stacks->head_a)->content >= num)
					{
						rotate_func(stacks, 'a');
						sa_func(stacks->head_a);
						(stacks->head_a) = (stacks->head_a)->next;
					}
					while (find_pos(stacks->head_a, find_min(stacks->head_a)) != 1)
						rev_rotate_func(stacks, 'a');
				}
				else
				{
					if (find_last_node(stacks->head_a)->content != prev)
					{
						rev_rotate_func(stacks, 'a');
						sa_func(stacks->head_a);
					}
					while (find_pos(stacks->head_a, find_max(stacks->head_a)) != ft_lstsize(stacks->head_a))
						rev_rotate_func(stacks, 'a');
				}
			}
		}
	}
}

void	not_sorting(t_stacks *stacks)
{
	if (ft_lstsize(stacks->head_a) == 2)
		sa_func(stacks->head_a);
	else if (ft_lstsize(stacks->head_a) == 3)
		sort_three_func(stacks);
	else if (ft_lstsize(stacks->head_a) == 4)
		sort_four_func(stacks);
	else if (ft_lstsize(stacks->head_a) == 5)
		sort_five_func(stacks);
	else
		mech_turk_algo(stacks);
}
