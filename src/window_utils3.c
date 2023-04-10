/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:26:27 by jralph            #+#    #+#             */
/*   Updated: 2023/04/10 02:08:38 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_colors(t_win *win)
{
	int	i;

	i = 0;
	win->colors = malloc(sizeof(int) * N_COLORS);
	if (!win->colors)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc failed"));
	while (i < 256)
	{
		win->colors[i] = ft_bgr_into_int(i, 0, i);
		win->colors[i + 256] = ft_bgr_into_int(255, 0, 255 - i);
		win->colors[i + 512] = ft_bgr_into_int(255, i, 0);
		win->colors[i + 768] = ft_bgr_into_int(255 - i, 255, 255);
		win->colors[i + 1024] = ft_bgr_into_int(0, 255, i);
		win->colors[i + 1280] = ft_bgr_into_int(255, 255 - i, 0);
		win->colors[i + 1536] = ft_bgr_into_int(255 - i, 0, 0);
		i++;
	}
}
