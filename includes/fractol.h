/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:47:34 by jose              #+#    #+#             */
/*   Updated: 2023/04/06 18:28:30 by jralph           ###   ########.fr       */
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
# define FPS 37
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define CENTER_X WIN_W / 2
# define CENTER_Y WIN_H / 2
# define DECA_PIXEL 2.5
# define N_COLORS 1792

/*	pixel's color BGRA	*/
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0x0000FF
# define GREEN 0x00FF00
# define BLUE 0xFF0000
# define ALPHA 0x000000

/* error's macro	*/
# define BAD_PARAMETERS 0
# define MLX_INIT_FAILED 1
# define MLX_WIN_FAILED 2
# define MALLOC_FAILED 3

/*	keybord's macro	*/
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_D 100
# define KEY_S 115
# define KEY_I 105
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ZOOM 65451
# define KEY_DEZOOM 65453

typedef int		v4si __attribute__ ((vector_size (4)));
typedef double	v4df __attribute__ ((vector_size (8)));

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	v4df	x;
	v4df	y;
	v4df	zoom;
	int		iteration_max;
	t_image	*img;
	t_list	*lst_str;
	char	fract;
	int		*colors;
}	t_win;

/*	window.c	*/
void	*ft_initial_window(char *fractal_name);

/*	window_utils.c	*/
void	ft_win_lst_str(t_win *win);
void	ft_win_lst_str_suite(t_win *win);

/*	window_utils2.c	*/
void	ft_mandelbrot(t_win *win);

/*	window_utils3.c	*/
void	ft_win_colors(t_win *win);

/*	error.c	*/
void	ft_error(int err, char *msg_err);

/*	events.c	*/
int		ft_close_win(t_win *window);
int		ft_event_manager(int keycode, t_win *win);
int		ft_event_manager2(int button, int x, int y, t_win *win);

/*	events_utils.c	*/
void	ft_zoom(t_win *win, int x, int y);
void	ft_dezoom(t_win *win, int x, int y);

/*	events_utils2.c	*/
void	ft_go_right(t_win *win);
void	ft_go_left(t_win *win);
void 	ft_go_up(t_win *win);
void	ft_go_down(t_win *win);

/*	events_utils3.c	*/
void	ft_increase_i_max(t_win *win);
void	ft_decrease_i_max(t_win *win);

/*	draw.c	*/
int		ft_draw_fractal(t_win *win);
void	ft_draw_f(t_win *win);

/*	draw_utils.c	*/
char	ft_nbr_red(int color);
char	ft_nbr_green(int color);
char	ft_nbr_blue(int color);
char	ft_nbr_alpha(int color);
int		ft_bgr_into_int(int b, int g, int r);

/*	free.c	*/
void	ft_free_window(t_win *window);

#endif