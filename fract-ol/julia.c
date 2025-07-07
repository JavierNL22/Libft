/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:50:42 by jnavalla          #+#    #+#             */
/*   Updated: 2025/07/06 16:00:49 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractal *f)
{
	int	py;

	py = 0;
	f->max_iter = calculate_max_iter(f->scale);
	while (py < HEIGHT)
	{
		julia_x(f, py);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		py++;
	}
}

int	calc_julia_iterations(t_fractal *f, double zr, double zi, int max_iter)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + f->julia_re;
		zi = 2 * zr * zi + f->julia_im;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	julia_x(t_fractal *f, int py)
{
	int		px;
	double	zr;
	double	zi;
	int		iter;

	zi = (py - f->center_y) * f->scale;
	px = 0;
	while (px < WIDTH)
	{
		zr = (px - f->center_x) * f->scale;
		iter = calc_julia_iterations(f, zr, zi, f->max_iter);
		put_pixel(f, px, py, calc_color(iter, f->max_iter));
		px++;
	}
}
