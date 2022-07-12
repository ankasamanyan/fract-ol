/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:53:48 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/12 04:23:32 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_mlx *mlx, t_colour colour, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	t_copmlx	temp;
	double		tmp;

	mlx->iter = 0;
	//og_one //max_iter 50
	constant.x = -0.79;
	constant.y = 0.15;
	
	//medusa_one //max_iter 50
	// constant.x = 0.3;
	// constant.y = -0.01;
	
	//kinda_cool_one //max_iter 200
	// constant.x = 0.28;
	// constant.y = 0.008;
	
	//weird_filled_one //max_iter 50
	// constant.x = -0.391;
	// constant.y = -0.587;
	
	//suriken_one //100 //50
	// constant.x = 0.3;
	// constant.y = 0.6;
	complex = screen_to_complex(mlx, x, y);
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
		// my_mlx_pixel_put(&mlx->img, x, y, og_colours(colour, mlx->iter));
		my_mlx_pixel_put(&mlx->img, x, y, ukr_colours(colour, mlx->iter));
	}
}
