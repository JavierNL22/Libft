/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:40:10 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/21 15:40:21 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (start > ft_strlen(s))
		return ((char *)ft_calloc (1, 1));
	if (ft_strlen(s) - start < len)
	{
		substr = (char *)ft_calloc(ft_strlen(s) + 1 - start, 1);
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, &s[start], ft_strlen(s) + 1 - start);
		return (substr);
	}
	substr = (char *)ft_calloc(len + 1, 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
