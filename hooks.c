/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:47 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/09/04 23:16:11 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	x_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	iter_change(t_mlx *mlx, int yes)
{
	mlx->max_iter += yes * 50;
	mlx->draw_func(mlx);
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
	if (keycode == K_PLUS)
		iter_change(mlx, 1);
	if (keycode == K_MINUS)
		iter_change(mlx, -1);
	if (keycode == K_C)
		colour_key(mlx);
	return (0);
}

void	colour_key(t_mlx *mlx)
{
	if (mlx->colour_func == &bernstein_colours)
	{
		mlx->colour_func = &hippy_colours;
		mlx->draw_func(mlx);
	}
	else if (mlx->colour_func == &hippy_colours)
	{
		mlx->colour_func = &acid_colours;
		mlx->draw_func(mlx);
	}
	else if (mlx->colour_func == &acid_colours)
	{
		mlx->colour_func = &black_white_colours;
		mlx->draw_func(mlx);
	}
	else if (mlx->colour_func == &black_white_colours)
	{
		mlx->colour_func = &pastel_colours;
		mlx->draw_func(mlx);
	}
	else if (mlx->colour_func == &pastel_colours)
	{
		mlx->colour_func = &bernstein_colours;
		mlx->draw_func(mlx);
	}
}

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	t_mouse_pos	pos;

	pos.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	pos.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	if (button == 4 || button == 1)
	{
		zoom_calc(mlx, &pos, 1);
		mlx->draw_func(mlx);
	}
	if (button == 5 || button == 2)
	{
		zoom_calc(mlx, &pos, 0);
		mlx->draw_func(mlx);
	}
	return (0);
}
