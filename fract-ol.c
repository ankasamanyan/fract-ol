/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:10:35 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/22 17:48:48 by ankasamanya      ###   ########.fr       */
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

void	draw( t_mlx mlx)
{
	int x;
	int y;
	int	iter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			screen_to_complex(mlx, x, y);
			mandelbrot(mlx, (double)x, (double)y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
}

t_copmlex	screen_to_complex(t_mlx mlx, int x, int y)
{
	t_copmlex	complex;

	complex.x = ((x / (double)WIDTH) * (mlx.max_x - mlx.min_x)) + mlx.min_x;
	complex.y = ((y / (double)HEIGHT) * (mlx.max_y - mlx.min_x)) + mlx.min_y;
	return (complex);
}

void	mandelbrot(t_mlx mlx, double x, double y)
{
	double	start_x;
	double	start_y;
	double	temp_x;
	int		iter;

	iter = 0;
	start_x = x;
	start_y = y;
	
	while ((pow(x, 2) + pow(y, 2)) < 4 && iter < MAX_ITER)
	{
		temp_x = x;
		x = pow(x, 2.0) + (2 * sqrt(-1.0) * y * x) +  pow(y, 2.0);
		y = 2 * y * temp_x + start_y;
	}
	// return (iter);
	if (iter == MAX_ITER)
		my_mlx_pixel_put(&mlx.img, x, y, 0x00000000);
	else if (iter < MAX_ITER)
		my_mlx_pixel_put(&mlx.img, x, y, 0x00B852D9); 
}

int main(int argc, char *argv[])
{
	t_mlx	mlx;
	
	mlx.mlx = mlx_init(); //2560x1600
	input_check(argc, argv, &mlx);
	
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	//нарисовать изображение тут
	draw(mlx);
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