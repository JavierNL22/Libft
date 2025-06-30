/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:45:23 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/29 01:04:01 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_max_iter(double scale)
{
    return (int)(100 + log(1.0 / scale) * 20);
}

void put_pixel(t_fractal *f, int x, int y, int color)
{
    int offset = y * f->line_length + x * (f->bpp / 8);
    *(int *)(f->addr + offset) = color;
}

void	draw_fractal(t_fractal *f)
{
	int		px, py;

	f->max_iter = calculate_max_iter(f->scale);
	for (py = 0; py < HEIGHT; py++)
	{
		for (px = 0; px < WIDTH; px++)
		{
			double	c_re = (px - f->centerX) * f->scale;
			double	c_im = (py - f->centerY) * f->scale;
			double	z_re = 0, z_im = 0;
			int		iter = 0;

			while (z_re * z_re + z_im * z_im <= 4 && iter < f->max_iter)
			{
				double z_new = z_re * z_re - z_im * z_im + c_re;
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_new;
				iter++;
			}

			int color;
			if (iter == f->max_iter)
				color = 0x000000; // interior del conjunto
			else
			{
				double t = (double)iter / f->max_iter;
				int r = (int)(9 * (1 - t) * t * t * t * 255);
				int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
				int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
				color = (r << 16) | (g << 8) | b;
			}
			put_pixel(f, px, py, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int mouse_hook(int button, int x, int y, t_fractal *f)
{
    double zoom_factor;
    double c_re, c_im;

    if (button == 4 || button == 5)
    {
        // 1. Calcular el número complejo bajo el cursor antes del zoom
        c_re = (x - f->centerX) * f->scale;
        c_im = (y - f->centerY) * f->scale;

        // 2. Ajustar la escala
        if (button == 4)
            zoom_factor = 0.8; // zoom in
        else
            zoom_factor = 1.25; // zoom out

        f->scale *= zoom_factor;

        // 3. Ajustar el centro para que el mismo punto siga bajo el cursor
        f->centerX = x - c_re / f->scale;
        f->centerY = y - c_im / f->scale;

        draw_fractal(f);
    }
    return (0);
}
int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int main()
{
    t_fractal f;


    f.mlx = mlx_init();
    f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractal");

    f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
    f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_length, &f.endian);
    f.scale = 4.0 / WIDTH;
    f.centerX = WIDTH / 2.0;
    f.centerY = HEIGHT / 2.0;
    f.fast_mode = 0;
    mlx_mouse_hook(f.win, mouse_hook, &f);
    mlx_hook(f.win, 17, 0, close_window, &f);
    draw_fractal(&f);

    mlx_loop(f.mlx);
}
