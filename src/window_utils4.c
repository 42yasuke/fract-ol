/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/04/13 16:52:08 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_nbr_dot(char *nbr_str)
{
	int	i;
	int	nbr_dot;

	i = 0;
	nbr_dot = 0;
	if (!nbr_str)
		return (false);
	while (nbr_str[i])
	{
		if (nbr_str[i] == '.')
			nbr_dot++;
		i++;
	}
	return (nbr_dot < 2)
}

int	ft_good_nbr_str(char *nbr_str)
{
	int	i;

	i = 0;
	if (!nbr_str)
		return (false);
	while (nbr_str[i])
	{
		if (!ft_isdigit(nbr_str[i]))
		{
			if (nbr_str[i] != '-' || nbr_str[i] != '.')
				return (false);
			else if (nbr_str[i] == '-' && i != 0)
				return (false);
			else if (nbr_str[i] == '.')
				if (!ft_nbr_dot(nbr_str))
					return (false);
		}
		i++;
	}
	return (ft_good_nbr(nbr_str));
}
