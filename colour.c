/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:24:40 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/10 12:47:18 by akasaman         ###   ########.fr       */
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
	colour.r = 9.0 * (1.0 - x) * pow(x, 3.0) * 255;
	colour.g = 15.0 * pow((1.0 - x), 2.0) * pow(x, 2.0) * 255; 
	colour.b = 8.5 * pow((1.0 - x), 3.0) * x * 255;
	return (get_colour(colour));
}
