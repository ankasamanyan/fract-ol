/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:37 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/13 10:21:53 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_check(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 2)
	{
		ft_printf("\033[0;31m");
		ft_printf("\n\n\t\t\t\t\t=======================================================");
		ft_printf("\n\n\t\t\t\t\t   <<<>>>  Error: Wrong number of arguments!  <<<>>>\n\n");
        ft_printf("\t\t\t\t\t=======================================================\n\n");
		ft_printf("\033[0m");
		ft_printf("\033[0;33m");
        ft_printf("Try: './fractol <flag> <colour>'\n\n");
        ft_printf("For Julia sets: './fractol <flag> <colour> <julia_set_number>' \n\n");
		ft_printf("\033[0m");
		ft_printf("==================================================\t=========================\t=========================\n");
		ft_printf("|\tNAME OF THE SET\t\t|\tFLAG\t |\t|\t  COLOUR \t|\t|    JULIA SET NUMBER   |\n");
		ft_printf("==================================================\t=========================\t=========================\n");
		ft_printf("|\tMandelbrot\t\t|\t -m\t |\t|\tbernstein\t|\t|\t    1\t\t|\n");
		ft_printf("|\tBurning ship\t\t|\t -b\t |\t|\tdrugy\t\t|\t|\t    2\t\t|\n");
		ft_printf("|\tJulia\t\t\t|\t -j\t |\t|\tmonochrome\t|\t|\t    3\t\t|\n");
		ft_printf("==================================================\t=========================\t=========================\n");
        ft_printf("\033[0;33m Examples: './fractol -m bernstein'\n\t   './fractol -j drugy 3' \033[0m\n\n");
		exit(0);
	}
    return 0;
}