/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:40 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 14:04:48 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_add_image(t_win *win)
{
	win->img = malloc(sizeof(*(win->img)));
	if (!win->img)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc_img"));
	win->img->img = mlx_xpm_file_to_image(win->mlx, "image/noir.xpm", \
	&win->img->width, &win->img->height);
	if (!win->img->img)
		(ft_free_window(win), ft_error(win, MLX_IMG_FAILED, "mlx_image"));
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp, \
	&win->img->size_line, &win->img->endian);
}

static void	ft_initial_all(t_win *win)
{
	win->mlx = NULL;
	win->mlx_win = NULL;
	win->x[0] = 0;
	win->y[0] = 0;
	win->zoom[0] = 0;
	win->iteration_max = 0;
	win->img = NULL;
	win->lst_str = NULL;
	win->fract = 0;
	win->colors = NULL;
	win->use_colors = false;
	win->x_j[0] = 0;
	win->y_j[0] = 0;
}

void	*ft_initial_window(char **av)
{
	t_win	*win;

	win = malloc(sizeof(*win));
	if (!win)
		return (ft_error(NULL, MALLOC_FAILED, "malloc_window"), NULL);
	ft_initial_all(win);
	win->mlx = mlx_init();
	if (!win->mlx)
		(ft_error(win, MLX_INIT_FAILED, "mlx_init"));
	win->mlx_win = mlx_new_window(win->mlx, WIN_W, WIN_H, "FRACTOL");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(win, MLX_WIN_FAILED, "mlx_win"));
	if (!ft_strncmp(av[1], "m", 1))
		(ft_mandelbrot(win), win->fract = 'm');
	else if (!ft_strncmp(av[1], "j", 1))
		(ft_julia(win, av[2], av[3]), win->fract = 'j');
	else if (!ft_strncmp(av[1], "b", 1))
		(ft_burning_ship(win), win->fract = 'b');
	(ft_add_image(win), ft_win_lst_str(win), ft_win_colors(win));
	return (ft_draw_f(win), win);
}
