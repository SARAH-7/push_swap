/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:55:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/29 20:21:21 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_or_single_sign(char *arg)
{
	if (!isdigit_issign(*arg) || (*(arg + 1) == '-'
			|| *(arg + 1) == '+') || ((*arg == '-' || *arg == '+')
			&& ((*(arg + 1) == ' ' || *(arg + 1) == '\0'))))
		return (0);
	return (1);
}

int	sign_n_num(char *arg)
{
	if ((ft_isdigit(*arg) && (*(arg + 1) == '-' || *(arg + 1) == '+')))
		return (0);
	else if ((*arg == '-' || *arg == '+') && (ft_isdigit(*(arg - 1))))
		return (0);
	return (1);
}

int	entries_check(char *arg)
{
	int	k;

	k = 0;
	if (!arg)
		return (0);
	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (*arg == '\0')
			return (k);
		if (!double_or_single_sign(arg))
			return (0);
		k = 1;
		if (!sign_n_num(arg))
			return (0);
		else
			arg++;
		while (ft_isdigit(*arg))
			arg++;
		if (*arg != ' ' && *arg != '\0')
			return (0);
	}
	return (1);
}

int	input_check(char **split_nums)
{
	char	*arg;

	if (!split_nums)
		return (0);
	(void)*(split_nums++);
	while (*split_nums)
	{
		arg = *(split_nums);
		if (!entries_check(arg) || *arg == '\0')
			return (0);
		(void)*(split_nums++);
	}
	return (1);
}
