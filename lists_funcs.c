/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:35:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/21 11:11:10 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_lstsize(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	pb_lstsize_b(t_stack *b)
{
	int	i;

	if (!b)
		return (0);
	i = 0;
	while (b)
	{
		i++;
		b = b->next;
	}
	return (i);
}

t_stack	*pb_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	pb_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*add;

	if (*lst)
	{
		add = pb_lstlast(*lst);
		add->next = new;
	}
	else
		*lst = new;
	return (*new);
}
