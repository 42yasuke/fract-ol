/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:11 by jose              #+#    #+#             */
/*   Updated: 2023/03/20 13:48:58 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_win *win, int x, int y)
{
	int	deca_x;
	int	deca_y;

	deca_x = (int)fabs((float)(CENTER_X - x));
	deca_y = (int)fabs((float)(CENTER_Y - y));
	if (CENTER_X < x)
		win->x = win->x + ((double)deca_x) * (1.0 / win->zoom);
	else
		win->x = win->x - ((double)deca_x) * (1.0 / win->zoom);
	if (CENTER_Y < y)
		win->y = win->y - ((double)deca_y) * (1.0 / win->zoom);
	else
		win->y = win->y + ((double)deca_y) * (1.0 / win->zoom);
	win->zoom = win->zoom / 2.0 + win->zoom;
	win->x = win->x + (1.0 / win->zoom) * ((double)CENTER_X / 2.0);
	win->y = win->y - (1.0 / win->zoom) * ((double)CENTER_Y / 2.0);
	win->iteration_max = win->iteration_max + 5;
}

void	ft_dezoom(t_win *win, int x, int y)
{
	int	deca_x;
	int	deca_y;

	deca_x = (int)fabs((float)(CENTER_X - x));
	deca_y = (int)fabs((float)(CENTER_Y - y));
	if (CENTER_X < x)
		win->x = win->x + ((double)deca_x) * (1.0 / win->zoom);
	else
		win->x = win->x - ((double)deca_x) * (1.0 / win->zoom);
	if (CENTER_Y < y)
		win->y = win->y - ((double)deca_y) * (1.0 / win->zoom);
	else
		win->y = win->y + ((double)deca_y) * (1.0 / win->zoom);
	win->x = win->x - (1.0 / win->zoom) * ((double)CENTER_X / 2.0);
	win->y = win->y + (1.0 / win->zoom) * ((double)CENTER_Y / 2.0);
	win->zoom = win->zoom / 1.5;
	win->iteration_max = win->iteration_max - 5;
}
