/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:08:26 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/27 12:08:40 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	get_char_needed(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	num;
	char	*result;

	num = n;
	i = get_char_needed(n) - 1;
	result = ft_calloc(get_char_needed(n) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (num < 0)
	{
		num = num * -1;
		result[0] = '-';
	}
	while (num >= 10)
	{
		result[i] = (char)(num % 10) + 48;
		i --;
		num = num / 10;
	}
	result[i] = (char)num + 48;
	return (result);
}
