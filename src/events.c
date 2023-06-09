/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:55 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:48:05 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_win(t_win *window)
{
	return (ft_free_window(window), EXIT_SUCCESS);
}

int	ft_event_manager(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		return (ft_close_win(win));
	else if (keycode == KEY_UP || keycode == KEY_Z)
		(ft_go_up(win));
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		(ft_go_down(win));
	else if (keycode == KEY_LEFT || keycode == KEY_Q)
		(ft_go_left(win));
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		(ft_go_right(win));
	else if (keycode == KEY_ZOOM)
		ft_increase_i_max(win);
	else if (keycode == KEY_DEZOOM)
		ft_decrease_i_max(win);
	else if (keycode == KEY_C)
		win->use_colors = !win->use_colors;
	else if (keycode == KEY_I)
		ft_mandelbrot(win);
	(ft_lstclear(&win->lst_str, &free), ft_win_lst_str(win));
	return (EXIT_SUCCESS);
}

int	ft_event_manager2(int button, int x, int y, t_win *win)
{
	if (button == ON_MOUSEDOWN)
		(ft_zoom(win, x, y));
	else if (button == ON_MOUSEUP)
		(ft_dezoom(win, x, y));
	(ft_lstclear(&win->lst_str, &free), ft_win_lst_str(win));
	return (EXIT_SUCCESS);
}
