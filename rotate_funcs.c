/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/28 15:16:43 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_op(t_stack **t)
{
	int		swap;
	t_stack	*temp;

	if (!t || !*t || !(*t)->next)
		return ;
	temp = *t;
	if (temp != NULL && temp->next != NULL)
	{
		swap = temp->content;
		while (temp->next != NULL)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = swap;
	}
}

void	rotate_func(t_stack **a, t_stack **b, char ch)
{
	if (ch == 'a')
	{
		if (a == NULL || *a == NULL || (*a)->next == NULL)
			return ;
		rotate_op(a);
	}
	else if (ch == 'b')
	{
		if (b == NULL || (*b)->next == NULL)
			return ;
		rotate_op(b);
	}
	else
	{
		if (a == NULL || (*a)->next == NULL || b == NULL
			|| (*b)->next == NULL)
			return ;
		rotate_op(a);
		rotate_op(b);
	}
	ft_printf("r%c\n", ch);
}
