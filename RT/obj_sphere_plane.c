/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 13:26:21 by jerollin          #+#    #+#             */
/*   Updated: 2015/02/18 19:02:31 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, double *t)
{
	t_vect	tmp;
	double	d;

	set_to(&tmp, r_pos);
	subtract(&tmp, &(p->pos));
	d = -(dot_product(&p->dir, &tmp) / dot_product(&p->dir, r_dir));
	if (d > -0.0001 && d < *t)
	{
		*t = d;
		return (1);
	}
	return (0);
}

int		hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, double *t)
{
	t_vect	dist;
	double	b;
	double	d;
	double	i[2];
	int		ret;

	ret = 0;
	subtract(set_to(&dist, &s->pos), r_pos);
	b = dot_product(r_dir, &dist);
	d = (b * b) - dot_product(&dist, &dist) + (s->r * s->r);
	if (d < 0.0f)
		return (0);
	i[0] = b - sqrtf(d);
	i[1] = b + sqrtf(d);
	if ((i[0] > 0.1f) && (i[0] < *t))
	{
		*t = i[0];
		ret = 1;
	}
	if ((i[1] > 0.1) && (i[1] < *t))
	{
		*t = i[1];
		ret = 1;
	}
	return (ret);
}

void	norm_plane(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n)
{
	set_to(n, &(obj->dir));
	normalize(n);
	if (dot_product(n, ray) < 0)
		scalar_multiply(n, -1);
	(void)r_pos;
	(void)ray;
}

void	norm_sphere(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n)
{
	set_to(n, ray);
	add(n, r_pos);
	subtract(n, &(obj->pos));
	scalar_multiply(n, -1);
	normalize(n);
}
