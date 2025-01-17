/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:36:13 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 14:30:29 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || count == 0)
		return (d);
	if (d < s)
	{
		while (count--)
			*d++ = *s++;
	}
	else
	{
		d += count;
		s += count;
		while (count--)
			*(--d) = *(--s);
	}
	return (dest);
}
