/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:34:38 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/07 17:10:02 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_copmlx	screen_to_complex(t_mlx *mlx, int x, int y)
{
	t_copmlx	complex;

	complex.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	complex.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	// complex.x = (x / (double)WIDTH) * (mlx.max_x - mlx.min_x) + mlx.min_x;
	// complex.y = (y / (double)HEIGHT) * (mlx.max_y - mlx.min_y) + mlx.min_y;
	return (complex);
}

t_copmlx	vector_add(t_copmlx first, t_copmlx second)
{
	t_copmlx	complex;

	complex.x = first.x + second.x;
	complex.y = first.y + second.y;
	return (complex);
}

// x(a,b); y(c,d);
// x(ac-bd); y(ad+bc)
t_copmlx	vector_multpl(t_copmlx first, t_copmlx second)
{
	t_copmlx	complex;

	complex.x = (first.x * second.x) - (first.y * second.y);
	complex.y = 2 * (first.x * second.y);
	return (complex);
}

//z^2 + c 
t_copmlx	the_math(t_copmlx z, t_copmlx constant)
{
	z = vector_add(vector_multpl(z, z), constant);
	return (z);
}

// t_mouse_pos	screen_to_cplx(t_mlx *mlx, int x, int y)
// {
// 	t_copmlx	complex;

// 	complex.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
// 	complex.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
// 	// complex.x = (x / (double)WIDTH) * (mlx.max_x - mlx.min_x) + mlx.min_x;
// 	// complex.y = (y / (double)HEIGHT) * (mlx.max_y - mlx.min_y) + mlx.min_y;
// 	return (complex);