/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:37:07 by ziratya           #+#    #+#             */
/*   Updated: 2024/08/15 11:43:15 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_fractol(t_fractol *fractol)
{
    fractol->mlx_ptr = mlx_init();
    fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
    fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
    fractol->img_data = mlx_get_data_addr(fractol->img_ptr, &fractol->bpp, &fractol->size_line, &fractol->endian);
    fractol->zoom = 1.0;
    fractol->move_x = 0.0;
    fractol->move_y = 0.0;
    fractol->max_iter = 50;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}