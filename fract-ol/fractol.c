/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:45:23 by jnavalla          #+#    #+#             */
/*   Updated: 2025/07/07 10:42:34 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	double	zoom_factor;
	double	c_re;
	double	c_im;

	if (button == 4 || button == 5)
	{
		c_re = (x - f->center_x) * f->scale;
		c_im = (y - f->center_y) * f->scale;
		if (button == 4)
			zoom_factor = 0.8;
		else
			zoom_factor = 1.25;
		f->scale *= zoom_factor;
		f->center_x = x - c_re / f->scale;
		f->center_y = y - c_im / f->scale;
		f->draw(f);
	}
	return (0);
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		close_window(f);
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx); // Añade esto
	free(f->mlx);                // Libera la estructura de mlx
	exit(0);
	return (0);
}

int	parse_args(int argc, char **argv, t_fractal *f)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		f->draw = draw_mandelbrot;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		f->draw = draw_julia;
		if (argc > 2)
			f->julia_re = parse_double(argv[2]);
		else
			f->julia_re = 0.0;
		if (argc > 3)
			f->julia_im = parse_double(argv[3]);
		else
			f->julia_im = 0.8;
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!parse_args(argc, argv, &f))
	{
		ft_printf("Usage: ./fractol mandelbrot\n");
		ft_printf("       ./fractol julia [re im]\n");
		return (1);
	}
	f.mlx = mlx_init();
	if (!f.mlx)
		return (1);
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractal");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_length, &f.endian);
	f.scale = 4.0 / WIDTH;
	f.center_x = WIDTH / 2.0;
	f.center_y = HEIGHT / 2.0;
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_key_hook(f.win, key_hook, &f);
	f.draw(&f);
	mlx_loop(f.mlx);
	return (0);
}
