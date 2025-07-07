/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:00:38 by jnavalla          #+#    #+#             */
/*   Updated: 2025/07/07 00:25:29 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_max_iter(double scale)
{
	return ((int)(100 + log(1.0 / scale) * 20));
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	int	offset;

	offset = y * f->line_length + x * (f->bpp / 8);
	*(int *)(f->addr + offset) = color;
}

void	parse_digits(char *str, double *res, double *frac, int *decimal)
{
	while (*str)
	{
		if (*str == '.')
		{
			*decimal = 1;
			str++;
		}
		else if (*str >= '0' && *str <= '9')
		{
			if (!*decimal)
				*res = *res * 10 + (*str - '0');
			else
			{
				*res += (*str - '0') * (*frac);
				*frac *= 0.1;
			}
			str++;
		}
		else
			str++;
	}
}

double	parse_double(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		decimal;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	decimal = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	parse_digits(str, &result, &fraction, &decimal);
	return (result * sign);
}

int	calc_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x000000);
	if (iter < max_iter / 14)
		return (0x000033);
	else if (iter < max_iter / 12)
		return (0x0000CC);
	else if (iter < max_iter / 10)
		return (0x0033FF);
	else if (iter < max_iter / 8)
		return (0x009966);
	else if (iter < max_iter / 5)
		return (0x99FF33);
	else if (iter < max_iter / 4)
		return (0xFFFF00);
	else if (iter < max_iter / 3)
		return (0xFFCC00);
	else if (iter < max_iter / 2)
		return (0xFF9900);
	else if (iter < (2 * max_iter) / 3)
		return (0xFF6600);
	else if (iter < (3 * max_iter) / 4)
		return (0xCC3300);
	else
		return (0x660000);
}
