/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:47 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/07 19:30:06 by akasaman         ###   ########.fr       */
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
	// t_mouse_pos	mouse_pos;
	
	// mouse_pos = mlx->mouse_pos;
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
	// if(mouse_pos->x > (double)WIDTH || mouse_pos->y > (double)HEIGHT)
		// return (0);
	printf("button = %d x = %d  y = %d\n", button, x, y);
	int curr_mouse_pos_x;
	int curr_mouse_pos_y;
	mlx_mouse_get_pos(mlx->win, &curr_mouse_pos_x, &curr_mouse_pos_y);
	printf("%d\n", curr_mouse_pos_x);
	t_mouse_pos pos;
	pos.x = curr_mouse_pos_x;
	pos.y = curr_mouse_pos_y;
	pos.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	pos.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	if (button == 4)
	{
		// if (((mlx.max_x - mlx.min_y) / ZOOM_FACTOR) >= 0.000001)
		// {
			// mlx_destroy_image(mlx->mlx, &mlx->img);
			// mlx_clear_window(mlx->mlx, mlx->win);
			
			zoom(mlx, &pos, 1);
			printf("Doo stuff");
			draw_fractol(mlx, mlx->colour);
		// }
		
	}
	// else if (button == 5)
	// {	
	// 	zoom(mlx, mouse_pos, 0);
	// 	// draw_fractol(mlx, mlx.colour);
	// }
	return 0;
}
