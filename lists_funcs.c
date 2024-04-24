/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:35:34 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 11:21:23 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_a *a)
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
int	ft_lstsize_b(t_stack_b *b)
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

t_stack_a	*ft_lstlast(t_stack_a *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack_a	ft_lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*add;

	if (*lst)
	{
		add = ft_lstlast(*lst);
		add->next = new;
	}
	else
		*lst = new;
	return (*new);
}
