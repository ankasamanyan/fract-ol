/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:50:03 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/12 23:35:12 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_mlx *mlx)
{
	mlx->max_x = 2.75;
	mlx->min_x = - 3.25;
	mlx->max_y = 1.4;
	mlx->min_y = -2.1;
}

void	burningship(t_mlx *mlx, t_colour colour, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	double		tmp;

	mlx->iter = 0;
	constant = screen_to_complex(mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while ((complex.x * complex.x + complex.y * complex.y < 4) && (mlx->iter < MAX_ITER))
	{
		tmp = complex.x * complex.x - complex.y * complex.y + constant.x;
		complex.y = ft_abs(2 * complex.x * complex.y) + constant.y;
		complex.x = tmp;
		mlx->iter++;
	}
	if (mlx->iter == MAX_ITER)
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
	else if (mlx->iter < MAX_ITER)
	{
		// my_mlx_pixel_put(&mlx->img, x, y, og_colours(colour, mlx->iter));
		my_mlx_pixel_put(&mlx->img, x, y, drugy_colours(colour, mlx->iter));
	}
}
