/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:14:43 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/22 14:14:54 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	num_words;

	i = 0;
	num_words = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			num_words++;
		i++;
	}
	return (num_words);
}

static size_t	ft_word_length(char const *word_start, char c)
{
	size_t	i;

	i = 0;
	while (word_start[i] != c && word_start[i] != 0)
		i++;
	return (i);
}

void	ft_free_split(char **split, size_t j)
{
	while (j > 0)
	{
		free(split[--j]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		if (s[i] != c)
		{
			result[j] = ft_substr(s, i, ft_word_length(&s[i], c));
			if (!result[j++])
			{
				ft_free_split(result, j);
				return (NULL);
			}
			i = i + ft_word_length(&s[i], c) - 1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
