/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:36:46 by ziratya           #+#    #+#             */
/*   Updated: 2024/08/15 13:02:32 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandelbrot(t_fractol *fractol)
{
    int x, y;
    double pr, pi;
    double new_re, new_im, old_re, old_im;
    int i;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            pr = 1.5 * (x - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->move_x;
            pi = (y - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->move_y;
            new_re = new_im = old_re = old_im = 0;
            i = 0;
            while (i < fractol->max_iter && (new_re * new_re + new_im * new_im) <= 4)
            {
                old_re = new_re;
                old_im = new_im;
                new_re = old_re * old_re - old_im * old_im + pr;
                new_im = 2 * old_re * old_im + pi;
                i++;
            }
            if (i == fractol->max_iter)
                fractol->img_data[(x * fractol->bpp / 8) + (y * fractol->size_line)] = 0x00;
            else
                fractol->img_data[(x * fractol->bpp / 8) + (y * fractol->size_line)] = 0xFF;
        }
    }
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img_ptr, 0, 0);
}