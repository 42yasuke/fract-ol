/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:38:15 by jose              #+#    #+#             */
/*   Updated: 2023/04/17 13:25:02 by jralph           ###   ########.fr       */
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

	i = nbr_div - 1;
	res = nbr;
	while(i > 0)
	{
		res %= 10;
		i--;
	}
	return (res);
}

static char	*ft_dtoa(double nbr)
{
	int		res;
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*str;

	i = 0;
	str = ft_itoa((int)nbr);
	if (!str)
		return (NULL);
	nbr = fabs(nbr);
	tmp = str;
	(str = ft_strjoin(str, "."), free(tmp));
	while (i < 5)
	{
		nbr *= 10;
		res = ft_div_by_ten(ft_nbr_int((int)nbr), (int)nbr);
		tmp = str;
		tmp2 = ft_itoa(res);
		(str = ft_strjoin(str, tmp2), free(tmp), free(tmp2));
		i++;
	}
	return (str);
}

void	ft_win_lst_str(t_win *win)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_dtoa(win->x[0]);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	tmp2 = tmp;
	tmp = ft_strjoin("x ", tmp);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	(win->lst_str = ft_lstnew(tmp), free(tmp2));
	tmp = ft_dtoa(win->y[0]);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	tmp2 = tmp;
	tmp = ft_strjoin("y ", tmp);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	(ft_lstadd_back(&win->lst_str, ft_lstnew(tmp)), free(tmp2));
	ft_win_lst_str_suite(win);
}

void	ft_win_lst_str_suite(t_win *win)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_dtoa(win->zoom[0]);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	tmp2 = tmp;
	tmp = ft_strjoin("zoom ", tmp);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	(ft_lstadd_back(&win->lst_str, ft_lstnew(tmp)), free(tmp2));
	tmp = ft_itoa(win->iteration_max);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	tmp2 = tmp;
	tmp = ft_strjoin("i_max ", tmp);
	if (!tmp)
		(ft_free_window(win), ft_error(win, MALLOC_FAILED, "malloc failed"));
	(ft_lstadd_back(&win->lst_str, ft_lstnew(tmp)), free(tmp2));
}
