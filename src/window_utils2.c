/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:56:21 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 12:39:29 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_give_nbr_after_dot(char *nbr_str)
{
	char	*str;
	double	res;

	str = ft_strchr(nbr_str, '.');
	if (!str)
		return (0);
	str++;
	res = (double)ft_atoi(str);
	while (*str)
	{
		res /= 10.0;
		str++;
	}
	return (res);
}

void	ft_mandelbrot(t_win *win)
{
	win->x[0] = -3.0;
	win->y[0] = 3.0;
	win->zoom[0] = 100.0;
	win->iteration_max = 25;
}

void	ft_julia(t_win *win, char *nbr_str1, char *nbr_str2)
{
	ft_mandelbrot(win);
	win->x_j[0] = (double)ft_atoi(nbr_str1) + ft_give_nbr_after_dot(nbr_str1);
	win->y_j[0] = (double)ft_atoi(nbr_str2) + ft_give_nbr_after_dot(nbr_str2);
}

void	ft_burning_ship(t_win *win)
{
	ft_mandelbrot(win);
}
