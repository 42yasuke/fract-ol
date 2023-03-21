/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:11 by jose              #+#    #+#             */
/*   Updated: 2023/03/21 03:22:15 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_win *win)
{
	win->zoom = win->zoom * 1.05;
	win->iteration_max = win->iteration_max + 1;
}

void	ft_dezoom(t_win *win)
{
	win->zoom = win->zoom / 1.05;
	win->iteration_max = win->iteration_max - 1;
}
