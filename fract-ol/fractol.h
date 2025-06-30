/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:45:33 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/25 16:59:42 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_fractal
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    double scale;
    double centerX;
    double centerY;
    int bpp;
    int line_length;
    int endian;
    int     max_iter;
    int     fast_mode;
} t_fractal;

typedef struct s_complex
{
    double re; // Parte real
    double im; // Parte imaginaria
}   t_complex;

#endif