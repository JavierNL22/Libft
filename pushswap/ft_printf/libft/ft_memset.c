/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:14:05 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 16:58:01 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			counter;

	counter = 0;
	pointer = s;
	while (counter < n)
	{
		*pointer = c;
		counter++;
		pointer++;
	}
	return (s);
}
