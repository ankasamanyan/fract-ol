/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:34:34 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/09 10:28:29 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
int	getpxl(t_mlx *mlx, int x, int y)
{
	int	*pos;

	pos = (int *)(mlx->img.data + (y * mlx->img.size_l + \
								x * (mlx->img.bpp / 8)));
	return (*pos);
}

void	zoom(t_mlx *mlx, t_mouse_pos *mouse_pos, int in)
{
	t_mlx	dist_from;

	dist_from.min_x = mouse_pos->x - mlx->min_x;
	dist_from.max_x = mlx->max_x - mouse_pos->x;
	dist_from.min_y = mouse_pos->y - mlx->min_y;
	dist_from.max_y = mlx->max_y - mouse_pos->y;
	if (in == 1)
	{
		mlx->min_x = mlx->min_x + dist_from.min_x * ZOOM_FACTOR;
		mlx->max_x = mlx->max_x - dist_from.max_x * ZOOM_FACTOR;
		mlx->min_y = mlx->min_y + dist_from.min_y * ZOOM_FACTOR;
		mlx->max_y = mlx->max_y - dist_from.max_y * ZOOM_FACTOR;
	}
	else if (in == 0)
	{
		mlx->min_x = mlx->min_x - dist_from.min_x * ZOOM_FACTOR;
		mlx->max_x = mlx->max_x + dist_from.max_x * ZOOM_FACTOR;
		mlx->min_y = mlx->min_y - dist_from.min_y * ZOOM_FACTOR;
		mlx->max_y = mlx->max_y + dist_from.max_y * ZOOM_FACTOR;
	}
}

// void	move_it(t_mlx *mlx, t_mouse_pos *mouse_pos, int in)
// {
	
// }




// BONUS: BE HAPPY :)

// Tomorra(CHEWSDAY):
// make art for "menu"
// if more time
// make menu with keys for different sets 
