/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:34 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/14 18:08:10 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	main(void)
{
	char *src = NULL;
    char *dest = NULL;

    memcpy(dest, src, 0);
	printf("%p", memcpy(dest, src, 3));
	return (0);
}
