/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:24:40 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/12 04:25:59 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_colour(t_colour colour)
{
	int	trgb;
	trgb = colour.t << 24 | colour.r << 16 | colour.g << 8 | colour.b;
	return (trgb);
}

int	og_colours(t_colour colour, int iter)
{
	int	trgb;
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = 9.0 * (1.0 - x) * x * x * x * 255;
	colour.g = 15.0 * ((1.0 - x) * (1.0 - x)) * x * x * 255; 
	colour.b = 8.5 * ((1.0 - x) * (1.0 - x) * (1.0 - x)) * x * 255;
	return (get_colour(colour));
}

int	drugy_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = sin(0.1 * iter + 20 + x) * 127.5 + 127.5;
	colour.g = sin(0.15 * iter + 40 + x) * 127.5 + 127.5;
	colour.b = sin(0.2 * iter + 60 + x) * x * 127.5 + 127.5;
	return (get_colour(colour));
}

int	good_one_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = cos(0.1 * iter + 20 + x) * 127.5 + 127.5;
	colour.g = cos(0.15 * iter + 40 + x) * sin(0.15 * iter + 40 + x) * 127.5 + 127.5;
	colour.b = cos(0.2 * iter + 60 + x) * sin(0.2 * iter + 60 + x) * sin(0.2 * iter + 60 + x) *  x * 127.5 + 127.5;
	return (get_colour(colour));
}

int	also_good_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = sin(0.1 * iter + 20 + x) * 127.5 + 127.5;
	colour.g = sin(0.15 * iter + 40 + x) * sin(0.15 * iter + 40 + x) * 127.5 + 127.5;
	colour.b = sin(0.2 * iter + 60 + x) * sin(0.2 * iter + 60 + x) * sin(0.2 * iter + 60 + x) *  x * 127.5 + 127.5;
	return (get_colour(colour));
}

int	other_drugy_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = cos(0.2 * iter + 20 ) * 127.5 + 127.5;
	colour.g = cos(0.15 * iter + 10 ) * 127.5 + 127.5;
	colour.b = cos(0.1 * iter + 5 - x) * x * 127.5 + 127.5;
	return (get_colour(colour));
}

int	black_white_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = sin(0.16 * iter + 4 ) * 127.5 + 127.5;
	colour.g = sin(0.16 * iter + 4 ) * 127.5 + 127.5;
	colour.b = sin(0.16 * iter + 4 ) * 127.5 + 127.5;
	return (get_colour(colour));
}

int	ukr_colours(t_colour colour, int iter)
{
	double	x;

	x = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = cos(0.16 * iter + 4) * 127.5 + 127.5;
	colour.g = cos(0.16 * iter + 4) * 127.5 + 127.5;
	colour.b = cos(0.16 * iter + 4) * x * 127.5 + 127.5;
	return (get_colour(colour));
}
