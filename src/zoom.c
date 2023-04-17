/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:52:30 by jralph            #+#    #+#             */
/*   Updated: 2023/04/17 13:58:43 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_win *win, int x, int y)
{
	t_v4df	deca_x;
	t_v4df	deca_y;

	deca_x[0] = (double)(CENTER_X - x);
	deca_y[0] = (double)(CENTER_Y - y);
	win->zoom = win->zoom * 1.05;
	if (deca_x[0] < 0)
	{
		deca_x *= -1;
		ft_deca_d(win, deca_x);
	}
	else
		ft_deca_g(win, deca_x);
	if (deca_y[0] < 0)
	{
		deca_y *= -1;
		ft_deca_b(win, deca_y);
	}
	else
		ft_deca_h(win, deca_y);
}

void	ft_dezoom(t_win *win, int x, int y)
{
	t_v4df	deca_x;
	t_v4df	deca_y;

	win->zoom = win->zoom * 0.95;
	deca_x[0] = (double)(CENTER_X - x);
	deca_y[0] = (double)(CENTER_Y - y);
	if (deca_x[0] < 0)
	{
		deca_x *= -1;
		ft_deca_d(win, deca_x);
	}
	else
		ft_deca_g(win, deca_x);
	if (deca_y[0] < 0)
	{
		deca_y *= -1;
		ft_deca_b(win, deca_y);
	}
	else
		ft_deca_h(win, deca_y);
}
