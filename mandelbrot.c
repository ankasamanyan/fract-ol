/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:34:55 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/12 03:49:54 by ankasamanya      ###   ########.fr       */
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

void	mandelbrot(t_mlx *mlx, t_colour colour, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	t_copmlx	temp;

	mlx->iter = 0;
	constant = screen_to_complex(mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while ((complex.x * complex.x + complex.y * complex.y < 4) && (mlx->iter < MAX_ITER))
	{
		temp.x = complex.x;
		temp.y = complex.y;
		complex.x = temp.x * temp.x - temp.y * temp.y + constant.x;
		complex.y = 2 * temp.x * temp.y + constant.y;
		mlx->iter++;
	}
	if (mlx->iter == MAX_ITER)
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
	else if (mlx->iter < MAX_ITER)
	{
		//my_mlx_pixel_put(&mlx->img, x, y, og_colours(colour, mlx->iter));
		my_mlx_pixel_put(&mlx->img, x, y, drugy_colours(colour, mlx->iter));
	}
}
