/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:54:04 by jose              #+#    #+#             */
/*   Updated: 2023/03/21 03:42:03 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_go_right(t_win *win)
{
	win->x = win->x + (1.0 / win->zoom) * DECA_PIXEL;
}

void	ft_go_left(t_win *win)
{
	win->x = win->x - (1.0 / win->zoom) * DECA_PIXEL;
}

void 	ft_go_up(t_win *win)
{
	win->y = win->y + (1.0 / win->zoom) * DECA_PIXEL;;
}

void	ft_go_down(t_win *win)
{
	win->y = win->y - (1.0 / win->zoom) * DECA_PIXEL;
}
