/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:10:00 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 17:55:51 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pointerd;
	const unsigned char	*pointers;
	size_t				counter;

	if (src == dest)
		return (dest);
	if (dest == NULL && n == 0)
		return (NULL);
	if (n == 0)
		return (dest);
	counter = 0;
	pointerd = dest;
	pointers = src;
	while (counter < n)
	{
		*pointerd = *pointers;
		counter++;
		pointerd++;
		pointers++;
	}
	return (dest);
}
