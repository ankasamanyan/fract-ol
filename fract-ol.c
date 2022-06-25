/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:10:35 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/25 18:32:49 by akasaman         ###   ########.fr       */
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

void	mandelbrot(t_mlx mlx, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	int			iter;

	iter = 0;
	constant = screen_to_complex(mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while (((pow(complex.x, 2) + pow(complex.y, 2)) < 4) && (iter < MAX_ITER))
	{
		complex = the_math(complex, constant);
		iter++;
	}
	if (iter == MAX_ITER)
		my_mlx_pixel_put(&mlx.img, x, y, 0x00000000);
	else if (iter < MAX_ITER)
		my_mlx_pixel_put(&mlx.img, x, y, 0x00C09CE0); 
}

void	draw( t_mlx mlx)
{
	int 		x;
	int 		y;
	t_copmlx	complex;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot(mlx, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
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