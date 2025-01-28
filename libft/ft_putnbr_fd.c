/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:46:23 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/27 13:46:34 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	get_max_div(int n)
{
	int	i;

	i = 1000000000;
	while (n / i == 0)
	{
		i = i / 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	print;
	int		i;

	if (n == 0)
		write (fd, "0", 1);
	else
	{
		num = n;
		i = get_max_div(n);
		if (num < 0)
		{
			num = num * -1;
			write(fd, "-", 1);
		}
		while (i >= 10)
		{
			print = (char)(num / i + 48);
			write(fd, &print, 1);
			num = num % i;
			i = i / 10;
		}
		print = (char)(num / i + 48);
		write(fd, &print, 1);
	}
}
