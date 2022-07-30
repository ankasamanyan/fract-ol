/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:50:03 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/17 18:19:31 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_mlx *mlx)
{
	mlx->max_x = 2.75;
	mlx->min_x = -3.25;
	mlx->max_y = 1.4;
	mlx->min_y = -2.1;
	mlx->max_iter = 30;
	mlx->draw_func = &draw_burninghsip;
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
	while ((complex.x * complex.x + complex.y * complex.y < 4)
		&& (mlx->iter < mlx->max_iter))
	{
		tmp = complex.x * complex.x - complex.y * complex.y + constant.x;
		complex.y = ft_abs(2 * complex.x * complex.y) + constant.y;
		complex.x = tmp;
		mlx->iter++;
	}
	if (mlx->iter == mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
	else if (mlx->iter < mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, mlx->colour_func(mlx, mlx->iter));
}

void	draw_burninghsip( t_mlx *mlx, t_colour colour)
{
	int			x;
	int			y;
	t_copmlx	complex;
	t_input		input;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			burningship(mlx, colour, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
