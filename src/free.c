/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/03/26 14:53:21 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_window(t_win *win)
{
	if (!win)
		return ;
	if (win->img)
		(mlx_destroy_image(win->mlx, win->img->img), free(win->img));
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_loop_end(win->mlx);
}
