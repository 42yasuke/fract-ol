/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:18:42 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_window(t_win *win)
{
	if (!win)
		return ;
	if (win->img)
	{
		if (win->img->img)
			mlx_destroy_image(win->mlx, win->img->img);
		free(win->img);
	}
	if (win->lst_str)
		ft_lstclear(&win->lst_str, &free);
	free(win->colors);
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_loop_end(win->mlx);
}
