/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:54:00 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/20 16:54:13 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp_i;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (i < len && big[i] != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			temp_i = i;
			while (big[temp_i] == little[j] && temp_i < len)
			{
				if (little[j + 1] == 0)
					return ((char *)&big[i]);
				temp_i++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
