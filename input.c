/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:37 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/14 18:52:05 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_check(int argc, char **argv, t_mlx *mlx)
{
	argc_check(argc, argv, mlx);
	color_check(argc, argv, mlx);
	if (argc > 3)
		julia_set_check(argc, argv, mlx);
	return (0);
}

int	argc_check(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 3)
	{
		print_message();
		exit(0);
	}
	if ((ft_strncmp(argv[1], "-j", 3) == 0))
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

void	color_check(int argc, char **argv, t_mlx *mlx)
{
	if (ft_strncmp(argv[2], "blue", 5) == 0)
		mlx->colour_func = &bernstein_colours;
	else if (ft_strncmp(argv[2], "hippy", 6) == 0)
		mlx->colour_func = &hippy_colours;
	else if (ft_strncmp(argv[2], "acid", 5) == 0)
		mlx->colour_func = &acid_colours;
	else if (ft_strncmp(argv[2], "mono", 5) == 0)
		mlx->colour_func = &black_white_colours;
	else if (ft_strncmp(argv[2], "pastel", 7) == 0)
		mlx->colour_func = &pastel_colours;
	else
	{
		print_message();
		exit(0);
	}
}

void	julia_set_check(int argc, char **argv, t_mlx *mlx)
{
	number_check(argc, argv, mlx);
	if (ft_strncmp(argv[3], "3", 2) == 0)
	{
		mlx->julia_const.x = 0.28;
		mlx->julia_const.y = 0.008;
	}
	else if (ft_strncmp(argv[3], "4", 2) == 0)
	{
		mlx->julia_const.x = -0.4;
		mlx->julia_const.y = -0.59;
	}
	else
	{
		print_message();
		exit(0);
	}
}

void	number_check(int argc, char **argv, t_mlx *mlx)
{
	if (ft_strncmp(argv[3], "1", 2) == 0)
	{
		mlx->julia_const.x = -0.79;
		mlx->julia_const.y = 0.15;
	}
	else if (ft_strncmp(argv[3], "2", 2) == 0)
	{
		mlx->julia_const.x = 0.3;
		mlx->julia_const.y = -0.01;
	}
}


void	print_message(void)
{
	ft_printf("\033[0;31m\n\n\t\t\t\t\t================================");
	ft_printf("=======================");
	ft_printf("\n\n\t\t\t\t\t   <<<>>>  Error: Wrong number of arguments! ");
	ft_printf("<<<>>>\n\n");
    ft_printf("\t\t\t\t\t===================================");
	ft_printf("====================\n\n\033[0m");
    ft_printf("\033[0;33mHow to use fractal: './fractol <flag> <colour> ");
	ft_printf("(<julia_set_number)>'\033[0m\n\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\tNAME OF THE SET\t\t|\tFLAG\t |\t|\t  COLOUR \t|\t|");
	ft_printf("    JULIA SET NUMBER   |\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\t          \t\t|\t   \t |\t|\t  blue\t\t|\t|\t    1\t\t|\n");
	ft_printf("|\tMandelbrot\t\t|\t -m\t |\t|\t  hippy\t\t|\t|\t    2\t\t|\n");
	ft_printf("|\tBurning ship\t\t|\t -b\t |\t|\t  acid\t\t|\t|\t    3\t\t|\n");
	ft_printf("|\tJulia\t\t\t|\t -j\t |\t|\t  mono\t\t|\t|\t    4\t\t|\n");
	ft_printf("|\t          \t\t|\t   \t |\t|\t  pastel\t|\t|\t     \t\t|\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
    ft_printf("\033[0;33m Examples: \"./fractol -m blue\" ,");
	ft_printf(" \"./fractol -j hippy 3\" \033[0m\n\n");
}
