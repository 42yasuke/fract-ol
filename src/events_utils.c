/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:11 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 13:15:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_deca_g(t_win *win, v4df deca_x)
{
	win->x = win->x - 0.3 * deca_x * (1.0 / win->zoom);
}

static void	ft_deca_d(t_win *win, v4df deca_x)
{
	win->x = win->x + 0.3 * deca_x * (1.0 / win->zoom);
}

static void	ft_deca_h(t_win *win, v4df deca_x)
{
	win->y = win->y + 0.3 * deca_x * (1.0 / win->zoom);
}

static void	ft_deca_b(t_win *win, v4df deca_x)
{
	win->y = win->y - 0.3 * deca_x * (1.0 / win->zoom);
}

void	ft_zoom(t_win *win, int x, int y)
{
	v4df	deca_x;
	v4df	deca_y;

	deca_x[0] = (double)(CENTER_X - x);
	deca_y[0] = (double)(CENTER_Y - y);
	win->zoom = win->zoom * 1.05;
	if (deca_x[0] < 0)
		(deca_x *= -1, ft_deca_d(win, deca_x));
	else
		ft_deca_g(win, deca_x);
	if (deca_y[0] < 0)
		(deca_y *= -1, ft_deca_b(win, deca_y));
	else
		ft_deca_h(win, deca_y);
}


void	ft_dezoom(t_win *win, int x, int y)
{
	v4df	deca_x;
	v4df	deca_y;

	win->zoom = win->zoom * 0.95;
	deca_x[0] = (double)(CENTER_X - x);
	deca_y[0] = (double)(CENTER_Y - y);
	if (deca_x[0] < 0)
		(deca_x *= -1, ft_deca_d(win, deca_x));
	else
		ft_deca_g(win, deca_x);
	if (deca_y[0] < 0)
		(deca_y *= -1, ft_deca_b(win, deca_y));
	else
		ft_deca_h(win, deca_y);
}
