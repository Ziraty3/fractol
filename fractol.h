/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:35:51 by ziratya           #+#    #+#             */
/*   Updated: 2024/08/19 15:19:54 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
}				t_fractol;

void	draw_mandelbrot(t_fractol *fractol);
void	draw_julia(t_fractol *fractol, double cr, double ci);
int		handle_key(int key, t_fractol *fractol);
int		handle_mouse(int button, int x, int y, t_fractol *fractol);
void	init_fractol(t_fractol *fractol);
int		ft_strcmp(const char *s1, const char *s2);

#endif