/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:37:29 by ziratya           #+#    #+#             */
/*   Updated: 2024/08/15 13:08:02 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_key(int key, t_fractol *fractol)
{
    if (key == 65307) // Escape key
        exit(0);
    if (key == 65362) // Up arrow
        fractol->move_y -= 0.1 / fractol->zoom;
    if (key == 65364) // Down arrow
        fractol->move_y += 0.1 / fractol->zoom;
    if (key == 65361) // Left arrow
        fractol->move_x -= 0.1 / fractol->zoom;
    if (key == 65363) // Right arrow
        fractol->move_x += 0.1 / fractol->zoom;
    draw_mandelbrot(fractol); // Redraw Mandelbrot after movement
    return (0);
}

int handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;

    if (button == 4) // Scroll up
        fractol->zoom *= 1.1;
    if (button == 5) // Scroll down
        fractol->zoom /= 1.1;
    draw_mandelbrot(fractol); // Redraw Mandelbrot after zoom
    return (0);
}