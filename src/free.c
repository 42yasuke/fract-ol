/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/03/17 15:39:20 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_window(t_win *window)
{
	if (!window)
		return ;
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_loop_end(window->mlx);
}
