/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:03 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/20 15:50:15 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*read;

	read = s;
	i = 0;
	while (i < n)
	{
		if (((unsigned char)read[i]) == ((unsigned char)c))
		{
			return ((void *)&read[i]);
		}
		i++;
	}
	return (NULL);
}
