/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:57:56 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/28 15:39:48 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*first_arg(char	*str, char **av)
{
	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	if (!input_check(av))
	{
		write(2, "Error\n", 6);
		free(str);
		exit(EXIT_FAILURE);
	}
	return (str);
}

char	**parsing_avs(char **av)
{
	int		i;
	char	*tmp;
	char	*str;
	char	**split_nums;

	str = NULL;
	str = first_arg(str, av);
	if (!str)
		return (NULL);
	i = 2;
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp)
			return (free(str), NULL);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	split_nums = ft_split(str, ' ');
	return (free(str), split_nums);
}
