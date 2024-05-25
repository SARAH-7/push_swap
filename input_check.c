/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:55:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 10:56:33 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	func(char *arg)
{
	int	k;

	k = 0;
	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (*arg == '\0')
			return (k);
		if (!isdigit_issign(*arg) || (*(arg + 1) == '-'
				|| *(arg + 1) == '+') || ((*arg == '-' || *arg == '+')
				&& (*(arg + 1) == ' ' || *(arg + 1) == '\0')))
			return (k);
		k = 1;
		while (isdigit_issign(*arg))
			arg++;
		if (*arg != ' ' && *arg != '\0')
			return (0);
	}
	return (k);
}

int	input_check(char **split_nums)
{
	char	*arg;

	if (!split_nums)
		return (0);
	while (*split_nums)
	{
		arg = *split_nums;
		if (!func(arg))
			return (0);
		split_nums++;
	}
	return (1);
}
