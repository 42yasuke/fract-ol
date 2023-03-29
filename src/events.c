/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:55 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 12:38:06 by jose             ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

int	ft_event_manager2(int button, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (button == ON_MOUSEDOWN)
		(ft_zoom(win, x, y));
	else if (button == ON_MOUSEUP)
		(ft_dezoom(win, x, y));
	return (EXIT_SUCCESS);
}
