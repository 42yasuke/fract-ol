/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:11 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:55:12 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_deca_g(t_win *win, t_v4df deca_x)
{
	win->x = win->x - 0.3 * deca_x * (1.0 / win->zoom);
}

void	ft_deca_d(t_win *win, t_v4df deca_x)
{
	win->x = win->x + 0.3 * deca_x * (1.0 / win->zoom);
}

void	ft_deca_h(t_win *win, t_v4df deca_x)
{
	win->y = win->y + 0.3 * deca_x * (1.0 / win->zoom);
}

void	ft_deca_b(t_win *win, t_v4df deca_x)
{
	win->y = win->y - 0.3 * deca_x * (1.0 / win->zoom);
}
