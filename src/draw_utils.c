/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:46:15 by jose              #+#    #+#             */
/*   Updated: 2023/04/10 01:37:58 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	ft_nbr_blue(int color)
{
	return ((color & BLUE) >> 16);
}

char	ft_nbr_green(int color)
{
	return ((color & GREEN) >> 8);
}

char	ft_nbr_red(int color)
{
	return (color & RED);
}

char	ft_nbr_alpha(int color)
{
	return (color & ALPHA);
}

int	ft_bgr_into_int(int b, int g, int r)
{
	int	color;

	color = b;
	color = color << 16;
	color = color | (g << 8);
	color = color | r;
	return (color);
}