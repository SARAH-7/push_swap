/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:01:46 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 06:58:40 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_wordcount(const char *s, char c)
{
	int	num_of_words;
	int	i;

	i = 0;
	num_of_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num_of_words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (num_of_words);
}

void	ps_free_word(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ps_copy_str(const char *s, int numberofletters, char **trgh)
{
	int		j;
	char	*split;

	split = malloc((numberofletters) * sizeof(char));
	if (!split)
		return (ps_free_word(trgh), NULL);
	j = 0;
	while (j < numberofletters)
	{
		split[j] = *(s - numberofletters + j);
		j++;
	}
	split[j] = '\0';
	return (split);
}

int	assign_split(const char *s, char c, char **split)
{
	int		num_of_letters;

	while (*s)
	{
		num_of_letters = 0;
		while (*s && *s != c)
		{
			num_of_letters++;
			s++;
		}
		if (num_of_letters > 0)
		{
			*split = ps_copy_str (s, num_of_letters, split);
			if (!*split)
				return (free_split(split), 0);
			split++;
		}
		else
			s++;
	}
	*split = NULL;
	return (1);
}

char	**ps_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((ps_wordcount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!assign_split(s, c, split))
		return (NULL);
	return (split);
}
