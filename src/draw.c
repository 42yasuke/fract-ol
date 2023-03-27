/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:35:59 by jose              #+#    #+#             */
/*   Updated: 2023/03/27 13:33:54 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_calcul_z_i(t_win *win, int coord, double z_r, double z_i)
{
	double	c_i;

	c_i = win->y - (coord % 1000) / win->zoom;
	return (2 * z_i * z_r + c_i);
}

static double	ft_calcul_z_r(t_win *win, int coord, double z_r, double z_i)
{
	double	c_r;

	c_r = (coord / 1000) / win->zoom + win->x;
	return (z_r * z_r - z_i * z_i + c_r);
}

static int	ft_calcul(t_win *win, int coord)
{
	
	int		i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		color;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (i < win->iteration_max)
	{
		tmp = z_r;
		z_r = ft_calcul_z_r(win, coord, z_r, z_i);
		z_i = ft_calcul_z_i(win, coord, tmp, z_i);
		if (z_r * z_r + z_i * z_i >= 4)
			break ;
		i++;
	}
	if (i == win->iteration_max)
		return (BLACK);
	//color = i * BLUE / win->iteration_max;
	color = 0x0000FF00;
	return (color);
}

static void	ft_draw_pixel(t_win *win, int coord)
{
	int		color;
	char	*addr;

	color = ft_calcul(win, coord);
	addr = win->img->addr;
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 0] = ft_nbr_red(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 1] = ft_nbr_green(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 2] = ft_nbr_blue(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 3] = 0;
}

static int	ft_draw_f(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			ft_draw_pixel(win, x * 1000 + y);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

int	ft_draw_fractal(t_win *win)
{
	static int	fps = 0;
	if (fps % FPS == 0)
	{
		ft_draw_f(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img->img, 0, 0);
		mlx_do_sync(win->mlx);
	}
	fps++;
	return (EXIT_SUCCESS);
}
