/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:32:25 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/10 10:13:40 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_mlx *mlx)
{
	int		pxls;
	double	shiftval;

	pxls = HEIGHT * 0.1;
	shiftval = (mlx->max_x - mlx->min_x) / HEIGHT * pxls;
	mlx->min_y = mlx->min_y - shiftval;
	mlx->max_y =  mlx->max_y - shiftval;
	draw_fractol(mlx, mlx->colour);
}

void	move_down(t_mlx *mlx)
{
	int		pxls;
	double	shiftval;

	pxls = HEIGHT * 0.1;
	shiftval = (mlx->max_x - mlx->min_x) / HEIGHT * pxls;
	mlx->min_y = mlx->min_y + shiftval;
	mlx->max_y =  mlx->max_y + shiftval;
	draw_fractol(mlx, mlx->colour);
}

void	move_right(t_mlx *mlx)
{
	int		pxls;
	double	shiftval;

	pxls = HEIGHT * 0.1;
	shiftval = (mlx->max_x - mlx->min_x) / HEIGHT * pxls;
	mlx->min_x = mlx->min_x + shiftval;
	mlx->max_x =  mlx->max_x + shiftval;
	draw_fractol(mlx, mlx->colour);
}

void	move_left(t_mlx *mlx)
{
	int		pxls;
	double	shiftval;

	pxls = HEIGHT * 0.1;
	shiftval = (mlx->max_x - mlx->min_x) / HEIGHT * pxls;
	mlx->min_x = mlx->min_x - shiftval;
	mlx->max_x =  mlx->max_x - shiftval;
	draw_fractol(mlx, mlx->colour);
}