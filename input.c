/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:37 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/14 19:23:15 by ankasamanya      ###   ########.fr       */
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
		if (argc == 4)
			return (0);
		print_message();
		exit(0);
	}
	if (argc != 3)
	{
		print_message();
		exit(0);
	}
	return (0);
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
