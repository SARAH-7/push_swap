/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/22 19:49:09 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_func(t_stack **a)
{
	t_stack	*temp;
	t_stack	*new_stack;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	new_stack = NULL;
	while (temp->next != NULL)
	{
		new_stack = temp;
		temp = temp->next;
	}
	temp->next = *a;
	*a = temp;
	new_stack->next = NULL;
}

void	rrb_func(t_stack **b)
{
	t_stack	*temp;
	t_stack	*new_stack;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	new_stack = NULL;
	while (temp->next != NULL)
	{
		new_stack = temp;
		temp = temp->next;
	}
	temp->next = *b;
	*b = temp;
	new_stack->next = NULL;
}

void	rev_rotate_func(t_stack **a, t_stack **b, char ch)

{
	int	i;

	i = 0;
	if (ch == 'a')
	{
		rra_func(a);
		i++;
	}
	else if (ch == 'b')
	{
		if (b == NULL || (*b)->next == NULL)
			return ;
		rrb_func(b);
		i++;
	}
	if (i == 1)
		ft_printf("rra\n");
	else if (i == 2)
		ft_printf("rrb\n");
	else if (i == 3)
	{
		if (a == NULL || (*a)->next == NULL || b == NULL
			|| (*b)->next == NULL)
			return ;
		rra_func(a);
		rrb_func(b);
		ft_printf("rrr\n");
	}
}
