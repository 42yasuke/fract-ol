/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:35:59 by jose              #+#    #+#             */
/*   Updated: 2023/04/10 02:12:39 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static v4df	ft_calcul_z_i(t_win *win, int coord, v4df z_r, v4df z_i)
{
	v4df	c_i;

	c_i = win->y - (coord % 1000) / win->zoom;
	return (2 * z_i * z_r + c_i);
}

static v4df	ft_calcul_z_r(t_win *win, int coord, v4df z_r, v4df z_i)
{
	v4df	c_r;

	c_r = (coord / 1000) / win->zoom + win->x;
	return (z_r * z_r - z_i * z_i + c_r);
}

static int	ft_calcul(t_win *win, int coord)
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
		z_r = ft_calcul_z_r(win, coord, z_r, z_i);
		z_i = ft_calcul_z_i(win, coord, tmp, z_i);
		tmp = z_r * z_r + z_i * z_i;
		if (tmp[0] >= 4)
			break ;
		i++;
	}
	return (i);
}

static void	ft_draw_pixel(t_win *win, int coord)
{
	int		color;
	int		i_pix;
	char	*addr;

	i_pix = ft_calcul(win, coord);
	if (i_pix == win->iteration_max)
		color = BLACK;
	else if (!win->use_colors)
		color = i_pix * RED / win->iteration_max;
	else
	{
		i_pix = i_pix * (N_COLORS - 1) / win->iteration_max;
		color = win->colors[i_pix];
	}
	addr = win->img->addr;
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 0] = ft_nbr_blue(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 1] = ft_nbr_green(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 2] = ft_nbr_red(color);
	addr[(coord / 1000) * (win->img->bpp / 8) + (coord % 1000) * win->img->size_line + 3] = 0;
}

void	ft_draw_f(t_win *win)
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
}

int	ft_draw_fractal(t_win *win)
{
	static int	fps = 0;
	t_list		*tmp;
	int			i;

	tmp = win->lst_str;
	i = 0;
	if (fps % FPS == 0)
	{
		ft_draw_f(win);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img->img, 0, 0);
		while (tmp)
		{
			mlx_string_put(win->mlx, win->mlx_win, 0, (i + 1) * 15, 0xFFFFFF, tmp->content);
			tmp = tmp->next;
			i++;
		}
		mlx_do_sync(win->mlx);
	}
	fps++;
	if (fps == INT_MAX)
		fps = 0;
	return (EXIT_SUCCESS);
}
