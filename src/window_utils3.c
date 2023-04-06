/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:26:27 by jralph            #+#    #+#             */
/*   Updated: 2023/04/06 18:32:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_colors(t_win *win);
{
	int	i;

	i = 0;
	win->colors = malloc(sizeof(int) * N_COLORS);
	if (!win->colors)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc failed"));
	whie (i < 256)
	{
		int	ft_bgr_into_int(int b, int g, int r)
		/* noir vers magenta */
		win->colors[i] = ft_bgr_into_int(i, 0, i);
		/* magenta vers bleu */
		win->colors[i + 256] = ft_bgr_into_int(255, 0, 255 - i);
		/* bleu vers cyan */
		win->colors[i + 512] = ft_bgr_into_int(255, i, 0);
		/* cyan vers vert */
		win->colors[i + 768] = ft_bgr_into_int(255 - i, 255, 255);
		/* vert vers jaune */
		win->colors[i + 1024] = ft_bgr_into_int(0, 255, i);
		/* jaune vers rouge */
		win->colors[i + 1280] = ft_bgr_into_int(255, 255 - i, 0);
		/* rouge vers noir */
		win->colors[i + 1536] = ft_bgr_into_int(255 - i, 0, 0);
		i++;
	}
}
