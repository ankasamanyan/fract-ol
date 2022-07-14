/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:53:48 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/14 18:12:23 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_innit(t_mlx *mlx)
{
	mlx->max_x = 2.25;
	mlx->min_x = -2.25;
	mlx->max_y = 1.25;
	mlx->min_y = -1.25;
	// mlx->set_func = &julia;
	mlx->draw_func = &draw_julia;
}

void	julia(t_mlx *mlx, t_colour colour, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	t_copmlx	temp;
	double		tmp;

	mlx->iter = 0;
	//dragon_one //max_iter 50
	// constant.x = -0.79;
	// constant.y = 0.15;

	// //medusa_one //max_iter 50
	// constant.x = 0.3;
	// constant.y = -0.01;

	//kinda_cool_one //max_iter 200
	// constant.x = 0.28;
	// constant.y = 0.008;

	//sawblades_one //max_iter 50
	// constant.x = -0.4;
	// constant.y = -0.59;
	constant = mlx->julia_const;

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
		my_mlx_pixel_put(&mlx->img, x, y, mlx->colour_func(colour, mlx->iter));
}

void	draw_julia( t_mlx *mlx, t_colour colour)
{
	int 		x;
	int 		y;
	t_copmlx	complex;
	t_input		input;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			julia(mlx, colour, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}