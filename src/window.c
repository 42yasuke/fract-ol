/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:40 by jose              #+#    #+#             */
/*   Updated: 2023/04/13 12:36:46 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_add_image(t_win *win)
{
	win->img = malloc(sizeof(*(win->img)));
	if (!win->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_img"));
	win->img->img = mlx_xpm_file_to_image(win->mlx, "image/noir.xpm", &win->img->width, &win->img->height);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp, &win->img->size_line, &win->img->endian);
}

void	*ft_initial_window(char **av)
{
	t_win	*win;

	win = malloc(sizeof(*win));
	if (!win)
		return (ft_error(MALLOC_FAILED, "malloc_window"), NULL);
	win->mlx = mlx_init();
	if (!win->mlx)
		(ft_error(MLX_INIT_FAILED, "mlx_init"));
	win->mlx_win = mlx_new_window(win->mlx, WIN_W, WIN_H, "FRACTOL");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(MLX_WIN_FAILED, "mlx_win"));
	if (!ft_strncmp(av[1], "m", 1))
		(ft_mandelbrot(win), win->fract = 'm');
	else if (!ft_strncmp(av[1], "j", 1))
		(ft_julia(win, av[2], av[3]), win->fract = 'j');
	ft_add_image(win);
	win->lst_str = NULL;
	ft_win_lst_str(win);
	win->colors = NULL;
	ft_win_colors(win);
	win->use_colors = false;
	return (ft_draw_f(win), win);
}
