/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:54:04 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:59:49 by jralph           ###   ########.fr       */
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

void	ft_go_up(t_win *win)
{
	win->y = win->y + (1.0 / win->zoom) * DECA_PIXEL;
}

void	ft_go_down(t_win *win)
{
	win->y = win->y - (1.0 / win->zoom) * DECA_PIXEL;
}
