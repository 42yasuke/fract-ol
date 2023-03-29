/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:15:03 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 21:50:46 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_increase_i_max(t_win *win)
{
	if (win->iteration_max < INT_MAX)
		win->iteration_max += 1;
}

void	ft_decrease_i_max(t_win *win)
{
	if (win->iteration_max > INT_MIN)
		win->iteration_max -= 1;
}
