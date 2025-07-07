/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:56:57 by jnavalla          #+#    #+#             */
/*   Updated: 2025/03/22 16:57:56 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_print_data(char c, va_list ap);
int	ft_printf(char const *str, ...);
int	ft_putnbr_base(unsigned long num, char *base);
int	ft_putptr_base(unsigned long num, char *base);

#endif
