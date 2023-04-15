/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:48:13 by jose              #+#    #+#             */
/*   Updated: 2023/04/15 11:58:02 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static v4df	ft_calcul_z_i(t_win *win, v4df z_r, v4df z_i)
{
	v4df	c_i;

	c_i = win->y_j;
	return (2 * z_i * z_r + c_i);
}

static v4df	ft_calcul_z_r(t_win *win, v4df z_r, v4df z_i)
{
	v4df	c_r;

	c_r = win->x_j;
	return (z_r * z_r - z_i * z_i + c_r);
}

int	ft_calcul_j(t_win *win)
{
	
	int		i;
	v4df	z_r;
	v4df	z_i;
	v4df	tmp;

	i = 0;
	z_r[0] = 0;
	z_i[0] = 0;
	while (i < win->iteration_max)
	{
		tmp = z_r;
		z_r = ft_calcul_z_r(win, z_r, z_i);
		z_i = ft_calcul_z_i(win, tmp, z_i);
		tmp = z_r * z_r + z_i * z_i;
		if (tmp[0] >= 4)
			break ;
		i++;
	}
	return (i);
}