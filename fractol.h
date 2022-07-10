/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:27 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/10 13:14:45 by akasaman         ###   ########.fr       */
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

# define WIDTH  1080 //960		//1440		//720		//1080
# define HEIGHT 585 //640		//780		//390		//585

# define MAX_ITER 255
# define ZOOM_FACTOR 0.5

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

typedef struct s_mouse_pos
{
	double x;
	double y;
}	t_mouse_pos;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			iter;
	int			type;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	t_img		img;
	t_colour	colour;
	t_mouse_pos	mouse_pos;
	// t_copmlx	complex;
}	t_mlx;

typedef struct s_copmlx
{
	double	x;
	double	y;
}	t_copmlx;

// Window  Management 
int				x_close(t_mlx *mlx);
int				key_handler(int keycode, t_mlx *mlx);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
// Input 
int				input_check(int argc, char **argv, t_mlx *mlx);
// Mandelbrot set 
void			init_mandelbrot(t_mlx *mlx);
t_copmlx		screen_to_complex(t_mlx *mlx, int x, int y);
void			mandelbrot(t_mlx *mlx, t_colour colour, int x, int y);
void			draw_fractol( t_mlx* mlx, t_colour colour);
// The Math
t_copmlx		vector_add(t_copmlx first, t_copmlx second);
t_copmlx		vector_multpl(t_copmlx first, t_copmlx second);
t_copmlx		the_math(t_copmlx z, t_copmlx constant);
// Colours 
int				get_colour(t_colour colour);
int				og_colours(t_colour colour, int x);
int				other_colours(t_colour colour, int iter);
// Zoom
int				getpxl(t_mlx *mlx, int x, int y);
int 			mouse_handler(int button, int x, int y, t_mlx *mlx);
void			zoom(t_mlx *mlx, t_mouse_pos *mouse_pos, int in);
int				loop_hook_thingy(t_mlx *mlx);
// Move
void			move_up(t_mlx *mlx);
void			move_down(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			move_left(t_mlx *mlx);

#endif