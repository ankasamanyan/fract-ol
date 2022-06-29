/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:24:40 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/06/29 18:11:13 by ankasamanya      ###   ########.fr       */
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
	double	t;
	
	t = (double)iter / MAX_ITER;
	colour.t = 0;
	colour.r = 9.0 * (1.0 - t) * pow(t, 3.0) * 255;
	colour.g = 15.0 * pow((1.0 - t), 2.0) * pow(t, 2.0) * 255; 
	colour.b = 8.5 * pow((1.0 - t), 3.0) * t * 255;
	return (get_colour(colour));
}
