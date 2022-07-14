/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:10:35 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/14 18:27:34 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

// void	draw_fractol( t_mlx *mlx, t_colour colour)
// {
// 	int 		x;
// 	int 		y;
// 	t_copmlx	complex;
// 	t_input		input;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			mlx->set_func(mlx, colour, x, y);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
// }

void	init(char **argv, t_mlx *mlx)
{
	if (ft_strncmp(argv[1], "-m", 3) == 0)
		mandelbrot_init(mlx);
	else if (ft_strncmp(argv[1], "-j", 3) == 0)
		julia_innit(mlx);
	else if (ft_strncmp(argv[1], "-b", 3) == 0)
		burningship_init(mlx);
	else
	{
		print_message();
		exit(0);
	}
}

int main(int argc, char **argv)
{
	t_mlx	mlx;

	input_check(argc, argv, &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	init(argv, &mlx);
	mlx.draw_func(&mlx, mlx.colour);
	mlx_hook(mlx.win, ON_DESTROY, 0, x_close, &mlx);
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_handler, &mlx);
	mlx_mouse_hook(mlx.win, &mouse_handler, &mlx);
	mlx_loop(mlx.mlx);
	return 0;
}
