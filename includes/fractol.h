/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:47:34 by jose              #+#    #+#             */
/*   Updated: 2023/03/19 21:25:53 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx42/mlx.h"
# include "../mlx42/mlx_int.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

/*	window's macro	*/
# define WIN_W 600
# define WIN_H 600
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define FPS 15
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define CENTER_X WIN_W / 2
# define CENTER_Y WIN_H / 2

/* error's macro	*/
# define BAD_PARAMETERS 0
# define MLX_INIT_FAILED 1
# define MLX_WIN_FAILED 2
# define MALLOC_FAILED 3

/*	keybord's macro	*/
# define KEY_ESC 65307

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	double	x;
	double	y;
	double	zoom;
	int		iteration_max;
}	t_win;

/*	window.c	*/
void	*ft_initial_window(char *fractal_name);

/*	error.c	*/
void	ft_error(int err, char *msg_err);

/*	events.c	*/
int		ft_close_win(t_win *window);
int		ft_event_manager(int keycode, t_win *win);
int		ft_event_manager2(int button, int x, int y, t_win *win);

/*	events_utils.c	*/
void	ft_zoom(t_win *win, int x, int y);
void	ft_dezoom(t_win *win, int x, int y);

/*	draw.c	*/
int		ft_draw_fractal(t_win *win);

/*	free.c	*/
void	ft_free_window(t_win *window);

#endif