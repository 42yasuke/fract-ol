/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:50:52 by jose              #+#    #+#             */
/*   Updated: 2023/04/13 12:45:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	suite_main (t_win *win)
{
	mlx_loop_hook(win->mlx, &ft_draw_fractal, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, \
	&ft_close_win, win);
	mlx_hook(win->mlx_win, ButtonPress, ButtonPressMask, &ft_event_manager2, win);
	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win));
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2 || ac != 4)
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (ft_strlen(av[1]) != 1)
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (ft_strncmp(av[1], "m", 1) && ft_strncmp(av[1], "j", 1))
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (ac != 2 && !ft_strncmp(av[1], "m", 1))
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (ac != 4 && !ft_strncmp(av[1], "j", 1))
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (ac == 4)
	{
		if (!ft_good_nbr_str(av[1]) || !ft_good_nbr_str(av[1]))
			ft_error(BAD_PARAMETERS, "bad parameters");
	}
	win = ft_initial_window(av);
	return (suite_main(win));
}
