/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:58:22 by jerollin          #+#    #+#             */
/*   Updated: 2015/02/09 14:52:51 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void		ft_draw_line(t_p *e, int *a, int *b, unsigned int color)
{
	int		d[2];
	int		s[2];
	int		err;
	int		e2;

	if (!a || !b)
		return ;
	d[0] = abs(b[0] - a[0]);
	d[1] = abs(b[1] - a[1]);
	s[0] = a[0] < b[0] ? 1 : -1;
	s[1] = a[1] < b[1] ? 1 : -1;
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		mlx_pixel_put(e->mlx, e->win, a[0], a[1], color);
		if (((e2 = err) || 1) && a[0] == b[0] && a[1] == b[1])
			return ;
		if (e2 > -d[0] && ((err -= d[1]) || 1))
			a[0] += s[0];
		if (e2 < d[1] && ((err += d[0]) || 1))
			a[1] += s[1];
	}
}

void		ft_idraw_line(t_img *i, int *a, int *b, unsigned int color)
{
	int		d[2];
	int		s[2];
	int		err;
	int		e2;

	if (!a || !b)
		return ;
	d[0] = abs(b[0] - a[0]);
	d[1] = abs(b[1] - a[1]);
	s[0] = a[0] < b[0] ? 1 : -1;
	s[1] = a[1] < b[1] ? 1 : -1;
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		ft_pixel_put_to_image(i, a[0], a[1], color);
		if (((e2 = err) || 1) && a[0] == b[0] && a[1] == b[1])
			return ;
		if (e2 > -d[0] && ((err -= d[1]) || 1))
			a[0] += s[0];
		if (e2 < d[1] && ((err += d[0]) || 1))
			a[1] += s[1];
	}
}
