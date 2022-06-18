/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:27 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/18 19:24:43 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

# define WIDTH 500 //1440
# define HEIGHT 500 //780
# define MAX_ITER 50

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_DOWN = 125,
	K_UP = 126
};

typedef struct s_img
{
	void	*img_ptr;
	void	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		max_iter;
	int		type;
	// double	center_x;
	// double	center_y;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		scale;
	t_img	img;
}	t_mlx;

typedef struct s_complex
{
	double	compl_x;
	double	compl_y;
}	t_copmlex;

int	x_close(t_mlx *mlx);
int	key_handler(int keycode, t_mlx *mlx);
int	input_check(int argc, char **argv, t_mlx *mlx);

// typedef struct	s_data {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

#endif