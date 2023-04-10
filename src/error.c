/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:56:02 by jose              #+#    #+#             */
/*   Updated: 2023/04/10 03:47:30 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_usage(void)
{
	ft_printf("******** tutoriel ********\n");
	ft_printf("mandelbrot --> ./fractol m\n");
	ft_printf("julia --> ./fractol j x y\n");
}

void	ft_error(int err, char *msg_err)
{
	if (err == BAD_PARAMETERS)
		(ft_printf("Error : %s\n", msg_err), ft_usage());
	else if (err == MLX_INIT_FAILED)
		ft_printf("Error : %s\n", msg_err);
	else if (err == MLX_WIN_FAILED)
		ft_printf("Error : %s\n", msg_err);
	else if (err == MALLOC_FAILED)
		ft_printf("Error : %s\n", msg_err);
	exit(EXIT_FAILURE);
}