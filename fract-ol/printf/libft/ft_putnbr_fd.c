/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:46:23 by jnavalla          #+#    #+#             */
/*   Updated: 2025/03/22 17:05:15 by jnavalla         ###   ########.fr       */
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

ssize_t	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	print;
	int		i;
	int		count;

	count = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	num = n;
	i = get_max_div(n);
	if (num < 0)
	{
		num = -num;
		count += write(fd, "-", 1);
	}
	while (i >= 10)
	{
		print = (char)(num / i + '0');
		count += write(fd, &print, 1);
		num %= i;
		i /= 10;
	}
	print = (char)(num + '0');
	return (count + write(fd, &print, 1));
}
