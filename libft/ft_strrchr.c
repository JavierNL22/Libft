/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:50:32 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/20 14:50:47 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	c = (char) c;
	while (s[i] != c && i != 0)
	{
		i--;
	}
	if (s[i] == c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
