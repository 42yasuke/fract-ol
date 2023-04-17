/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:48:42 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:45:31 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_v4df	ft_calcul_z_i(t_win *win, int coord, t_v4df z_r, t_v4df z_i)
{
	t_v4df	c_i;
	t_v4df	a_zr;
	t_v4df	a_zi;

	c_i = win->y - (coord % 1000) / win->zoom;
	if (z_i[0] < 0)
		a_zi = -z_i;
	else
		a_zi = z_i;
	if (z_r[0] < 0)
		a_zr = -z_r;
	else
		a_zr = z_r;
	return (2 * a_zi * a_zr + c_i);
}

static t_v4df	ft_calcul_z_r(t_win *win, int coord, t_v4df z_r, t_v4df z_i)
{
	t_v4df	c_r;
	t_v4df	a_zr;
	t_v4df	a_zi;

	c_r = (coord / 1000) / win->zoom + win->x;
	if (z_i[0] < 0)
		a_zi = -z_i;
	else
		a_zi = z_i;
	if (z_r[0] < 0)
		a_zr = -z_r;
	else
		a_zr = z_r;
	return (z_r * z_r - z_i * z_i + c_r);
}

int	ft_calcul_b(t_win *win, int coord)
{
	int		i;
	t_v4df	z_r;
	t_v4df	z_i;
	t_v4df	tmp;

	i = 0;
	z_r[0] = 0;
	z_i[0] = 0;
	while (i < win->iteration_max)
	{
		tmp = z_r;
		z_r = ft_calcul_z_r(win, coord, z_r, z_i);
		z_i = ft_calcul_z_i(win, coord, tmp, z_i);
		tmp = z_r * z_r + z_i * z_i;
		if (tmp[0] >= 4)
			break ;
		i++;
	}
	return (i);
}
