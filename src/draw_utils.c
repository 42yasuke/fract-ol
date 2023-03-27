/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:46:15 by jose              #+#    #+#             */
/*   Updated: 2023/03/27 02:44:57 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_nbr_red(int color)
{
	return ((color & RED) >> 16);
}

int	ft_nbr_green(int color)
{
	return ((color & GREEN) >> 8);
}

int	ft_nbr_blue(int color)
{
	return (color & BLUE);
}
