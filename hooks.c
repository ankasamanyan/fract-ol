/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:47 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/07 17:11:29 by ankasamanya      ###   ########.fr       */
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
	t_mouse_pos	mouse_pos;
	
	mouse_pos = mlx->mouse_pos;
	// printf("%i\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	// if(keycode == 0)
	// 	zoom(mlx, mouse_pos);
	return (0);
}

int mouse_handler(int button, int x, int y, t_mlx *mlx, t_mouse_pos *mouse_pos)
{	//посмотри в код хайзенберга если не стработает этот прототип;
	if(mouse_pos->x > WIDTH || mouse_pos->y > HEIGHT)
	{
		return 0;
	}
	mouse_pos->x = x;
	mouse_pos->y = y;
	mouse_pos->x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	mouse_pos->y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	if (button == 4 || button == 1)
	{
		// if (((mlx.max_x - mlx.min_y) / ZOOM_FACTOR) >= 0.000001)
		// {
			zoom(mlx, mouse_pos, 1);
			// draw_fractol(mlx, mlx.colour);
		// }
		
	}
	else if (button == 5 || button == 2)
	{	
		zoom(mlx, mouse_pos, 0);
		// draw_fractol(mlx, mlx.colour);
	}
	// printf("button = %i x = %i  y = %i\n", button, x, y );
	return 0;
}
