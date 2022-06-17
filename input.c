/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:04:37 by akasaman          #+#    #+#             */
/*   Updated: 2022/06/17 15:30:29 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_check(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 2)
	{
		ft_printf("Error:\nWrong number of arguments!\n");
        ft_printf("========================================\n\n\n");
        ft_printf("");
		exit(0);
	}
    return 0;
    // exit (0);
}