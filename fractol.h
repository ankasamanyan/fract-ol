/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:27 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/14 19:35:29 by ankasamanya      ###   ########.fr       */
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

# define WIDTH  1080
# define HEIGHT 585

# define MAX_ITER 200
# define ZOOM_FACTOR 0.5

typedef struct s_mlx	t_mlx;

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
	K_UP = 126,
	K_PLUS = 24,
	K_MINUS = 27
};

typedef struct s_input
{
	int	set_name;
	int	colour;
	int	julia_set_number;
}	t_input;

typedef struct s_colour
{
	int	t;
	int	r;
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
	double	x;
	double	y;
}	t_mouse_pos;

typedef struct s_copmlx
{
	double	x;
	double	y;
}	t_copmlx;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			iter;
	int			max_iter;
	int			type;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	t_copmlx	julia_const;
	t_img		img;
	t_colour	colour;
	t_mouse_pos	mouse_pos;
	t_copmlx	complex;
	int			(*colour_func)(t_colour, int);
	void		(*draw_func)(t_mlx *, t_colour);
}	t_mlx;

// Window  Management 
int				x_close(t_mlx *mlx);
int				key_handler(int keycode, t_mlx *mlx);
int				mouse_handler(int button, int x, int y, t_mlx *mlx);
int				loop_hook_thingy(t_mlx *mlx);
// Drawing fractals
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			draw_fractol(t_mlx *mlx, t_colour colour);
// Input 
void			init(char **argv, t_mlx *mlx);
int				input_check(int argc, char **argv, t_mlx *mlx);
void			print_message(void);
int				argc_check(int argc, char **argv, t_mlx *mlx);
void			color_check(int argc, char **argv, t_mlx *mlx);
void			julia_set_check(int argc, char **argv, t_mlx *mlx);
void			number_check(int argc, char **argv, t_mlx *mlx);
// Mandelbrot set 
void			mandelbrot_init(t_mlx *mlx);
void			mandelbrot(t_mlx *mlx, t_colour colour, int x, int y);
void			draw_mandelbrot( t_mlx *mlx, t_colour colour);
// Julia set
void			julia_innit(t_mlx *mlx);
void			julia(t_mlx *mlx, t_colour colour, int x, int y);
void			draw_julia( t_mlx *mlx, t_colour colour);
// Burning ship
void			burningship_init(t_mlx *mlx);
void			burningship(t_mlx *mlx, t_colour colour, int x, int y);
void			draw_burninghsip( t_mlx *mlx, t_colour colour);
// The Math
double			ft_abs(double i);
t_copmlx		screen_to_complex(t_mlx *mlx, int x, int y);
t_copmlx		vector_add(t_copmlx first, t_copmlx second);
t_copmlx		vector_multpl(t_copmlx first, t_copmlx second);
t_copmlx		the_math(t_copmlx z, t_copmlx constant);
// Colours 
int				get_colour(t_colour colour);
int				bernstein_colours(t_colour colour, int x);
int				hippy_colours(t_colour colour, int iter);
int				pastel_colours(t_colour colour, int iter); //pastel //good_one
int				acid_colours(t_colour colour, int iter); //acid //also_good_one
int				black_white_colours(t_colour colour, int iter);
int				drugy_colours(t_colour colour, int iter);
int				ukr_colours(t_colour colour, int iter);
// Zoom
int				getpxl(t_mlx *mlx, int x, int y);
void			zoom_calc(t_mlx *mlx, t_mouse_pos *mouse_pos, int in);
// Move functions
void			move_up(t_mlx *mlx);
void			move_down(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			move_left(t_mlx *mlx);
#endif