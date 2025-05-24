/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:49:23 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/20 13:54:50 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	c = (char) c;
	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
