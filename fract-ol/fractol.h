/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:45:33 by jnavalla          #+#    #+#             */
/*   Updated: 2025/07/04 19:24:24 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;

	double	scale;
	double	center_x;
	double	center_y;
	int		max_iter;

	double	julia_re;
	double	julia_im;

	void	(*draw)(struct s_fractal *);
}	t_fractal;

// Funciones principales
int		parse_args(int argc, char **argv, t_fractal *f);
int		mouse_hook(int button, int x, int y, t_fractal *f);
int		key_hook(int keycode, t_fractal *f);
int		close_window(t_fractal *f);

// Funciones de renderizado
void	draw_mandelbrot(t_fractal *f);
void	draw_julia(t_fractal *f);

// Funciones auxiliares
int		calculate_max_iter(double scale);
void	put_pixel(t_fractal *f, int x, int y, int color);
double	parse_double(char *str); // Sustituye a atof

void	mandelbrot_x(t_fractal *f, int py);
void	julia_x(t_fractal *f, int py);
int		calc_color(int iter, int max_iter);
#endif