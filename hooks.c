/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:47 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/09 11:29:56 by ankasamanya      ###   ########.fr       */
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
	// printf("%i\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	// if (keycode == K_UP)
	// {
	// 	mlx->max_x = 
	// 	mlx->min_y = 
	// 	mlx->max_y = 
	// 	mlx->min_y = 
	// }
	//24 + plus
	//27 - minus
	return (0);
}

int mouse_handler(int button, int x, int y, t_mlx *mlx)
{	//посмотри в код хайзенберга если не стработает этот прототип;
	int curr_mouse_pos_x;
	int curr_mouse_pos_y;
	// mlx_mouse_get_pos(mlx->win, &curr_mouse_pos_x, &curr_mouse_pos_y);
	// printf("%d\n", curr_mouse_pos_x);
	t_mouse_pos pos;
	pos.x = curr_mouse_pos_x;
	pos.y = curr_mouse_pos_y;
	pos.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	pos.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	if (button == 4 || button == 1)
	{
		zoom(mlx, &pos, 1);
		draw_fractol(mlx, mlx->colour);
	}
	if (button == 5 || button == 2)
	{
		zoom(mlx, &pos, 0);
		draw_fractol(mlx, mlx->colour);
	}
	return 0;
}

int	loop_hook_thingy(t_mlx *mlx)
{
	mlx_do_sync(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0); 
	return (0);
}