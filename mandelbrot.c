/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:47:49 by jnavalla          #+#    #+#             */
/*   Updated: 2025/07/06 15:59:49 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *f)
{
	int	py;

	py = 0;
	f->max_iter = calculate_max_iter(f->scale);
	while (py < HEIGHT)
	{
		mandelbrot_x(f, py);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		py++;
	}
}

int	calc_iterations(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	mandelbrot_x(t_fractal *f, int py)
{
	int		px;
	double	cr;
	double	ci;
	int		iter;

	ci = (py - f->center_y) * f->scale;
	px = 0;
	while (px < WIDTH)
	{
		cr = (px - f->center_x) * f->scale;
		iter = calc_iterations(cr, ci, f->max_iter);
		put_pixel(f, px, py, calc_color(iter, f->max_iter));
		px++;
	}
}
