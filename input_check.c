/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:55:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 00:44:28 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(char **split_nums)
{
	char	*arg;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!split_nums)
		return (0);
	while (split_nums[i])
	{
		arg = split_nums[i];
		j = 0;
		k = 0;
		while (arg && arg[j])
		{
			while (arg[j] == ' ')
				j++;
			if (arg[j] == '\0')
				break ;
			if ((!isdigit_issign(arg[j]) || (arg[j + 1] == '-' || arg[j + 1] == '+') || ((arg[j] == '-' || arg[j] == '+')
						&& (arg[j + 1] == ' ' || arg[j + 1] == '\0'))))
				return (0);
			k = 1;
			j++;
		}
		if (k == 0)
			return (0);
		i++;
	}
	return (1);
}
