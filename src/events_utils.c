/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:11 by jose              #+#    #+#             */
/*   Updated: 2023/03/21 17:30:27 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_deca_g(t_win *win, int deca_x)
{
	win->x = win->x - (double)deca_x * (1.0 / win->zoom);
}

static void	ft_deca_d(t_win *win, int deca_x)
{
	win->x = win->x + (double)deca_x * (1.0 / win->zoom);
}

static void	ft_deca_h(t_win *win, int deca_x)
{
	win->y = win->y + (double)deca_x * (1.0 / win->zoom);
}

static void	ft_deca_b(t_win *win, int deca_x)
{
	win->y = win->y - (double)deca_x * (1.0 / win->zoom);
}

void	ft_zoom(t_win *win, int x, int y)
{
	int	deca_x;
	int	deca_y;

	deca_x = CENTER_X - x;
	deca_y = CENTER_Y - y;
	win->zoom = win->zoom * 1.05;
	win->iteration_max = win->iteration_max + 1;
	if (deca_x < 0)
		ft_deca_d(win, -deca_x);
	else
		ft_deca_g(win, deca_x);
	if (deca_y < 0)
		ft_deca_b(win, -deca_y);
	else
		ft_deca_h(win, deca_y);
}


void	ft_dezoom(t_win *win, int x, int y)
{
	int	deca_x;
	int	deca_y;

	win->zoom = win->zoom / 1.05;
	win->iteration_max = win->iteration_max - 1;
	deca_x = CENTER_X - x;
	deca_y = CENTER_Y - y;
	win->zoom = win->zoom * 1.05;
	win->iteration_max = win->iteration_max + 1;
	if (deca_x < 0)
		ft_deca_d(win, -deca_x);
	else
		ft_deca_g(win, deca_x);
	if (deca_y < 0)
		ft_deca_b(win, -deca_y);
	else
		ft_deca_h(win, deca_y);
}
