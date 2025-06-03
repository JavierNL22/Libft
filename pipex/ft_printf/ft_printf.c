/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:54:55 by jnavalla          #+#    #+#             */
/*   Updated: 2025/04/29 17:05:35 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr_base(unsigned long num, char *base)
{
	char	buffer[32];
	size_t	base_len;
	int		i;
	int		count;

	i = 0;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	while (num > 0)
	{
		buffer[i] = base[num % base_len];
		num /= base_len;
		i++;
	}
	count = i;
	while (i-- > 0)
		write(1, &buffer[i], 1);
	return (count);
}

int	ft_putptr_base(unsigned long num, char *base)
{
	char	buffer[32];
	size_t	base_len;
	int		i;
	int		count;

	i = 0;
	base_len = ft_strlen(base);
	if (num == 0)
		return (ft_putstr_fd("(nil)", 1));
	while (num > 0)
	{
		buffer[i] = base[num % base_len];
		num /= base_len;
		i++;
	}
	count = i;
	count = count + ft_putstr_fd("0x", 1);
	while (i-- > 0)
		write(1, &buffer[i], 1);
	return (count);
}

int	ft_print_data(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_fd((char) va_arg(ap, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (c == 'p')
		return (ft_putptr_base((uintptr_t)va_arg(ap, void *),
				"0123456789abcdef"));
	else if (c == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_print_data(str[i], ap);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
