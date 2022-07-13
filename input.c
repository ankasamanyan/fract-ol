/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:37 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/13 20:24:18 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_check(int argc, char **argv, t_mlx *mlx)
{
	argc_check(argc, argv, mlx);
	return 0;
}

int	argc_check(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 3)
	{
		print_message();
		exit(0);
	}
	if ((ft_strncmp(argv[1], "-j", ft_strlen(argv[1])) == 0))
	{
		if ( argc == 4)
			return 0;
		print_message();
		exit(0);
	}
	if (argc != 3 )
    {
		print_message();
		exit(0);
	}
	return(0);
}

// int	color_check(int argc, char **argv, t_mlx *mlx)
// {
	
// 	return (0);
// }

void	print_message(void)
{
	ft_printf("\033[0;31m\n\n\t\t\t\t\t=======================================================");
	ft_printf("\n\n\t\t\t\t\t   <<<>>>  Error: Wrong number of arguments!  <<<>>>\n\n");
    ft_printf("\t\t\t\t\t=======================================================\n\n\033[0m");
    ft_printf("\033[0;33mHow to use fractal: './fractol <flag> <colour> (<julia_set_number)>'\033[0m\n\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\tNAME OF THE SET\t\t|\tFLAG\t |\t|\t  COLOUR \t|\t|    JULIA SET NUMBER   |\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\tMandelbrot\t\t|\t -m\t |\t|\tbernstein\t|\t|\t    1\t\t|\n");
	ft_printf("|\tBurning ship\t\t|\t -b\t |\t|\tdrugy\t\t|\t|\t    2\t\t|\n");
	ft_printf("|\tJulia\t\t\t|\t -j\t |\t|\tmonochrome\t|\t|\t    3\t\t|\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
    ft_printf("\033[0;33m Examples: \"./fractol -m bernstein\" , \"./fractol -j drugy 3\" \033[0m\n\n");
}