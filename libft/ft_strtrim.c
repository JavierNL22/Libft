/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:49:11 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/22 13:49:25 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_is_in_set(char check, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == check)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	while (ft_is_in_set(s1[i], set) && i < ft_strlen(s1))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[i], set))
		i--;
	len = i - start;
	return (ft_substr(s1, start, len + 1));
}
