/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 03:33:42 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_op(t_stack **t)
{
	t_stack	*temp;
	t_stack	*new_stack;

	if (!t || !*t || !(*t)->next)
		return ;
	temp = *t;
	new_stack = NULL;
	while (temp->next != NULL)
	{
		new_stack = temp;
		temp = temp->next;
	}
	temp->next = *t;
	*t = temp;
	new_stack->next = NULL;
}

void	rev_rotate_func(t_stack **a, t_stack **b, char ch)
{
	if (ch == 'a')
	{
		if (a == NULL || (*a)->next == NULL)
			return ;
		rev_rotate_op(a);
	}
	else if (ch == 'b')
	{
		if (b == NULL || (*b)->next == NULL)
			return ;
		rev_rotate_op(b);
	}
	else
	{
		if (a == NULL || (*a)->next == NULL || b == NULL
			|| (*b)->next == NULL)
			return ;
		rev_rotate_op(a);
		rev_rotate_op(b);
	}
	ft_printf("rr%c\n", ch);
}
