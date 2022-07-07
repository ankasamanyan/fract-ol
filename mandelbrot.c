/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:34:55 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/07 16:48:42 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_mlx *mlx)
{
	mlx->max_x = 1.2;
	mlx->min_x = -2.4;
	mlx->max_y = 1;
	mlx->min_y = -1;
}

void	mandelbrot(t_mlx mlx, t_colour colour, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	int			iter;

	iter = 0;
	init_mandelbrot(&mlx);
	constant = screen_to_complex(&mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while (((pow(complex.x, 2) + pow(complex.y, 2)) < 4) && (iter < MAX_ITER))
	{
		complex = the_math(complex, constant);
		iter++;
	}
	if (iter == MAX_ITER)
		my_mlx_pixel_put(&mlx.img, x, y, 0x00000000);
	else if (iter < MAX_ITER)
	{
		// my_mlx_pixel_put(&mlx.img, x, y, og_colours(colour, iter));
		my_mlx_pixel_put(&mlx.img, x, y, og_colours(colour, iter)); 
	}
}
