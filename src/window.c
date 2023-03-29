/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:40 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 22:13:23 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_add_image(t_win *win)
{
	win->img = malloc(sizeof(*(win->img)));
	if (!win->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_img"));
	win->img->img = mlx_xpm_file_to_image(win->mlx, "/home/jose/C/fract-ol/image/noir.xpm", &win->img->width, &win->img->height);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp, &win->img->size_line, &win->img->endian);
}

void	*ft_initial_window(char *fractal_name)
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
	if (!ft_strncmp(fractal_name, "m", ft_strlen(fractal_name)))
		(ft_mandelbrot(win), win->fract = 'm');
	ft_add_image(win);
	win->lst_str = NULL;
	ft_win_lst_str(win);
	return (ft_draw_f(win), win);
}
