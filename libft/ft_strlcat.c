/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:42:39 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/17 13:17:07 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (size > 0)
	{
		while (i < size - 1 && src[j] != 0)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(dst) + ft_strlen(src));
}
