/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:17:11 by ziratya           #+#    #+#             */
/*   Updated: 2024/08/15 11:41:54 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol fractol;

    if (argc != 2)
    {
        printf("Usage: ./fractol [mandelbrot/julia]\n");
        return (1);
    }

    init_fractol(&fractol);

    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        draw_mandelbrot(&fractol);
    else if (ft_strcmp(argv[1], "julia") == 0)
        draw_julia(&fractol, -0.7, 0.27015);
    else
    {
        printf("Invalid fractal type.\n");
        return (1);
    }

    mlx_key_hook(fractol.win_ptr, handle_key, &fractol);
    mlx_mouse_hook(fractol.win_ptr, handle_mouse, &fractol);
    mlx_loop(fractol.mlx_ptr);
    return (0);
}