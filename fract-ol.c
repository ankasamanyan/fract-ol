/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:10:35 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/19 16:46:32 by akasaman         ###   ########.fr       */
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
	if (keycode == 'a')
		;
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

draw( t_mlx mlx)
{
	int x;
	int y;
	
	x = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			
			y++;
		}
		x++;
	}
	
	
}
t_copmlex	screen_to_complex(t_mlx mlx, int x, int y)
{
	t_copmlex	complex;

	complex.x = ((x / WIDTH) * (mlx.max_x - mlx.min_x)) + mlx.min_x;
	complex.y = ((y / HEIGHT) * (mlx.max_y - mlx.min_x)) + mlx.min_y;
	return (complex);
}

int main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*mlx_win;
	t_mlx	mlx;
	// int		i;
	// int		j;

	// i = 0;
	// j = 0;
	
	mlx.mlx = mlx_init(); //2560x1600
	input_check(argc, argv, &mlx);
	
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	//нарисовать изображение тут
	
	
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0); 
	
	//или же нарисовать изображение туть 
	mlx_hook(mlx.win, ON_DESTROY, 0, x_close, &mlx);
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_handler, &mlx);
	mlx_loop(mlx.mlx);
	return 0;
}

//img = mlx_new_image(mlx, 1920, 1080);
	// mlx_win = mlx_new_window(mlx, 1408, 760, "Hello world!");
	// while (i < 100)
	// {
	// 	// j = i + 1;
	// 	mlx_pixel_put(mlx, mlx_win, i, j, 0x000000FF);
		
	// 	i++;
	// }
	
	// mlx_pixel_put(mlx, mlx_win, 100, 100, 0x000000FF);
	
	// mlx_pixel_put(mlx, mlx_win, 100, 100, 0x000000FF);