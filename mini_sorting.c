/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:36:09 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 17:41:11 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_func(t_stacks *stacks)
{
	if (stacks->head_a->next->content < stacks->head_a->next->next->content
		&& stacks->head_a->next->next->content < stacks->head_a->content)
		rotate_func(stacks, 'a');
	if (stacks->head_a->content > stacks->head_a->next->content)
		sa_func(stacks->head_a);
	if (stacks->head_a->next->content > stacks->head_a->next->next->content
		&& stacks->head_a->next->next->content < stacks->head_a->content)
		rev_rotate_func(stacks, 'a');
	if (stacks->head_a->content < stacks->head_a->next->content
		&& stacks->head_a->next->content > stacks->head_a->next->next->content)
	{
		sa_func(stacks->head_a);
		rotate_func(stacks, 'a');
	}
}

void	sort_four_func(t_stacks *stacks)
{
	int	len;
	t_stack_a *a;

	a = stacks->head_a;
	len = 0;
	pb_func(stacks);
	sort_three_func(stacks);
	len = ft_lstsize_b(stacks->head_b);
	while (len--)
	{
		pa_func(stacks);
		if (find_pos(stacks->head_a, find_max(stacks->head_a)) == 1 && find_max(stacks->head_a) == ft_lstsize(stacks->head_a))
			rotate_func(stacks, 'a');
		else if (find_pos(stacks->head_a, find_max(stacks->head_a)) == ft_lstsize(stacks->head_a))
		{
			rev_rotate_func(stacks, 'a');
			sa_func(stacks->head_a);
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
		}
		else if (find_pos(stacks->head_a, find_min(stacks->head_a)) == 2)
			sa_func(stacks->head_a);
	}
}
void	sort_five_func(t_stacks *stacks)
{
	int	i;
	t_stack_a *a;

	a = stacks->head_a;
	pb_func(stacks);
	pb_func(stacks);
	sort_three_func(stacks);
	i = 2;
	while (i--)
	{
		if (find_max_b(stacks->head_b) != stacks->head_b->content)
			sb_func(stacks->head_b);
		if (find_min_b(stacks->head_b) > stacks->head_a->next->content && find_max_b(stacks->head_b) < find_max(stacks->head_a) && i == 1)
		{
			rev_rotate_func(stacks, 'a');
			pa_func(stacks);
			pa_func(stacks);
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			break ;
		}
		else if (find_max_b(stacks->head_b) > find_max(stacks->head_a) && find_min_b(stacks->head_b) > stacks->head_a->next->content && find_min_b(stacks->head_b) < find_max(stacks->head_a))
		{
			pa_func(stacks);
			rev_rotate_func(stacks, 'a');
			pa_func(stacks);
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			break ;
		}
		else if (find_min_b(stacks->head_b) > find_max(stacks->head_a))
		{
			pa_func(stacks);
			pa_func(stacks);
			rev_rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			break ;
		}
		pa_func(stacks);
		if (find_pos(stacks->head_a, find_max(stacks->head_a)) == ft_lstsize(stacks->head_a)
			&& (stacks->head_a)->next->next->content < (stacks->head_a)->content && i != 0)
		{
			rev_rotate_func(stacks, 'a');
			sa_func(stacks->head_a);
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
		}
		else if (find_pos(stacks->head_a, find_max(stacks->head_a)) == ft_lstsize(stacks->head_a)
			&& (stacks->head_a)->next->next->content < (stacks->head_a)->content && i == 0)
		{
			rev_rotate_func(stacks, 'a');
			sa_func(stacks->head_a);
			rev_rotate_func(stacks, 'a');
			sa_func(stacks->head_a);
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
			rotate_func(stacks, 'a');
		}
		else if (find_pos(stacks->head_a, find_min(stacks->head_a)) == 2
			&& find_min(stacks->head_a) < (stacks->head_a)->content && (stacks->head_a)->content != find_max(stacks->head_a))
				sa_func(stacks->head_a);
		else if (find_max(stacks->head_a) == ft_lstsize(stacks->head_a)
			|| (stacks->head_a)->content == find_max(stacks->head_a))
			rotate_func(stacks, 'a');
	}
}