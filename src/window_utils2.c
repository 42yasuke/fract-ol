/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:56:21 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 21:56:56 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_win *win)
{
	win->x[0] = -3.0;
	win->y[0] = 3.0;
	win->zoom[0] = 100.0;
	win->iteration_max = 25;
}