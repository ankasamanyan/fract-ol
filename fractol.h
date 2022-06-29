/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:27 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/28 19:03:18 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

# define WIDTH  1440
# define HEIGHT 780

# define MAX_ITER 255

# define MAX_X 1.2
# define MIN_X -2.4

# define MAX_Y 1
# define MIN_Y -1

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

typedef struct s_colour
{
	int	t;
	int r;
	int	g;
	int	b;
}	t_colour;


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
	void		*mlx;
	void		*win;
	int			max_iter;
	int			type;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	t_img		img;
	t_colour	colour;
}	t_mlx;

typedef struct s_copmlx
{
	double	x;
	double	y;
}	t_copmlx;

/* Window  Management */
int				x_close(t_mlx *mlx);
int				key_handler(int keycode, t_mlx *mlx);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
/* input */
int				input_check(int argc, char **argv, t_mlx *mlx);
/* Mandelbrot set */
t_copmlx		screen_to_complex(t_mlx mlx, int x, int y);
void			mandelbrot(t_mlx mlx, t_colour colour, int x, int y);
void			draw( t_mlx mlx, t_colour colour);
/* the Math */
t_copmlx		vector_add(t_copmlx first, t_copmlx second);
t_copmlx		vector_multpl(t_copmlx first, t_copmlx second);
t_copmlx		the_math(t_copmlx z, t_copmlx constant);
/* trgb */
int				create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int				get_colour(t_colour colour);
/* colours */
int	og_colours(t_colour colour, int x);
int	some_other_colours(t_colour colour, int iter);

#endif