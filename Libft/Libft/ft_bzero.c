/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:00:21 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 15:27:13 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*aux;

	aux = s;
	counter = 0;
	while (counter < n)
	{
		aux[counter] = 0;
		counter++;
	}
}
