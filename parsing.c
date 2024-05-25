/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:57:56 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 02:59:14 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing_avs(char **av)
{
	int		i;
	char	*tmp;
	char	*str;
	char	**split_nums;

	i = 2;
	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	if (!input_check(&av[1]))
	{
		ft_printf("Error\n");
		free(str);
		exit(EXIT_FAILURE);
	}
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp)
			return (free(str), NULL);
		free(str);
		if (!input_check(&av[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	split_nums = ft_split(str, ' ');
	return (free(str), split_nums);
}
