/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/21 03:56:30 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_func(t_stack **a)
{
	int		swap;
	t_stack	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
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

void	rb_func(t_stack **b)
{
	int		swap;
	t_stack	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
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
	int	i;

	i = 0;
	if (ch == 'a')
	{
		ra_func(a);
		i++;
	}
	else if (ch == 'b')
	{
		rb_func(b);
		i += 2;
	}
	if (i == 1)
		ft_printf("ra\n");
	else if (i == 2)
		ft_printf("rb\n");
	else if (i == 3)
	{
		ra_func(a);
		rb_func(b);
		ft_printf("rr\n");
	}
}
