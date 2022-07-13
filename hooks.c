/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:47 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/14 00:21:14 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	x_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	key_handler(int keycode, t_mlx *mlx)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == K_UP)
		move_up(mlx);
	if (keycode == K_DOWN)
		move_down(mlx);
	if (keycode == K_RIGHT)
		move_right(mlx);
	if (keycode == K_LEFT)
		move_left(mlx);
	return (0);
}

int mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	int			curr_mouse_pos_x;
	int			curr_mouse_pos_y;
	t_mouse_pos	pos;

	pos.x = curr_mouse_pos_x;
	pos.y = curr_mouse_pos_y;
	pos.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	pos.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	if (button == 4 || button == 1)
	{
		zoom_calc(mlx, &pos, 1);
		draw_fractol(mlx, mlx->colour);
	}
	if (button == 5 || button == 2)
	{
		zoom_calc(mlx, &pos, 0);
		draw_fractol(mlx, mlx->colour);
	}
	return 0;
}