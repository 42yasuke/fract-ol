/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 14:35:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_nbr_dot(char *nbr_str)
{
	int	i;
	int	nbr_dot;

	i = 0;
	nbr_dot = 0;
	if (!nbr_str)
		return (false);
	while (nbr_str[i])
	{
		if (nbr_str[i] == '.' && i == 0)
			return (false);
		if (nbr_str[i] == '.' && !nbr_str[i])
			return (false);
		if (nbr_str[i] == '.')
			nbr_dot++;
		i++;
	}
	return (nbr_dot < 2);
}

static int	ft_good_nbr(char *nbr_str)
{
	char	*str;
	int		nbr_before_dot;
	int		nbr_after_dot;
	int		i;

	nbr_before_dot = 0;
	nbr_after_dot = 0;
	i = 0;
	str = ft_strchr(nbr_str, '.');
	if (str)
		nbr_after_dot = ft_strlen(str) - 1;
	while (nbr_str[i])
	{
		if (nbr_str[i] == '.')
			break ;
		if (ft_isdigit(nbr_str[i]))
			nbr_before_dot++;
		i++;
	}
	if (!nbr_before_dot || (str && !nbr_after_dot))
		return (false);
	return ((nbr_before_dot < 2) && (nbr_after_dot < 10));
}

int	ft_good_nbr_str(char *nbr_str)
{
	int	i;

	i = 0;
	if (!nbr_str || !ft_strlen(nbr_str))
		return (false);
	while (nbr_str[i])
	{
		if (!ft_isdigit(nbr_str[i]))
		{
			if (nbr_str[i] != '-' && nbr_str[i] != '.')
				return (false);
			else if (nbr_str[i] == '-' && i != 0)
				return (false);
			else if (nbr_str[i] == '-' && ft_strlen(nbr_str) == 1)
				return (false);
			else if (nbr_str[i] == '.')
				if (!ft_nbr_dot(nbr_str))
					return (false);
		}
		i++;
	}
	return (ft_good_nbr(nbr_str));
}
