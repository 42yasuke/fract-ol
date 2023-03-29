/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:38:15 by jose              #+#    #+#             */
/*   Updated: 2023/03/29 14:07:00 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_nbr_int(int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	ft_div_by_ten(int nbr_div, int nbr)
{
	int	i;
	int	res;

	i = nbr_div;
	res = nbr;
	while(i)
	{
		res /= 10;
		i--;
	}
	return (res);
}

static char	*ft_dtoa(double nbr)
{
	int		res;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = ft_nbr_int((int)nbr);
	str = ft_itoa((int)nbr);
	if (!str)
		return (NULL);
	
	return (str);
}

void	ft_win_str(t_win *win)
{
	win->str = ft_dtoa(win->x);
	if (!win->str)
		ft_error();
}