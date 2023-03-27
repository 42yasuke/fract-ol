/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:46:15 by jose              #+#    #+#             */
/*   Updated: 2023/03/27 13:35:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	ft_nbr_red(int color)
{
	return ((color & RED) >> 24);
}

char	ft_nbr_green(int color)
{
	return ((color & GREEN) >> 16);
}

char	ft_nbr_blue(int color)
{
	return ((color & BLUE) >> 8);
}

char	ft_nbr_alpha(int color)
{
	return (color & ALPHA);
}