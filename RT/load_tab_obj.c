/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tab_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:33:21 by jerollin          #+#    #+#             */
/*   Updated: 2015/03/22 10:45:48 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

void	add_spot(t_env *e, char **tab, int size[2])
{
	int	i;

	if (ft_tablen((void**)tab) < 7)
		exit(ft_dprintf(2, "error :Not enouth info for spot"));
	i = e->n_spot;
	e->spots[i].pos.x = ft_atof(tab[1]);
	e->spots[i].pos.y = ft_atof(tab[2]);
	e->spots[i].pos.z = ft_atof(tab[3]);
	e->spots[i].r = ft_atof(tab[4]);
	e->spots[i].v = ft_atof(tab[5]);
	e->spots[i].b = ft_atof(tab[6]);
	e->spots[i].i = ft_atof(tab[7]);
	e->n_spot++;
	if (e->n_spot > size[1])
		exit(ft_dprintf(2, "error :Too many spots !\n"));
}

void	set_obj_triangle(t_obj *obj, char **tab)
{
	obj->hit = &hit_triangle;
	obj->norm = &norm_plane;
	obj->dir.x = ft_atof(tab[1]);
	obj->dir.y = ft_atof(tab[2]);
	obj->dir.z = ft_atof(tab[3]);
	obj->dir2.x = ft_atof(tab[4]);
	obj->dir2.y = ft_atof(tab[5]);
	obj->dir2.z = ft_atof(tab[6]);
	obj->dir3.x = ft_atof(tab[7]);
	obj->dir3.y = ft_atof(tab[8]);
	obj->dir3.z = ft_atof(tab[9]);
}

void	select_type(char **tab, t_obj *obj)
{
	if (!ft_strcmp(tab[0], "Sphere"))
	{
		obj->hit = &hit_sphere;
		obj->norm = &norm_sphere;
	}
	else if (!ft_strcmp(tab[0], "Plane"))
	{
		obj->hit = &hit_plane;
		obj->norm = &norm_plane;
	}
	else if (!ft_strcmp(tab[0], "Triangle"))
		set_obj_triangle(obj, tab);
	else if (!ft_strcmp(tab[0], "Cone"))
	{
		obj->hit = &hit_cone;
		obj->norm = &norm_cylinder;
	}
	else if (!ft_strcmp(tab[0], "Cylinder"))
	{
		obj->hit = &hit_cylinder;
		obj->norm = &norm_cylinder;
	}
}

void	add_obj_to_tab(t_env *e, char **tab, int i, int size[2])
{
	t_obj	*obj;

	if (tab && !ft_strcmp(tab[0], "Spot"))
	{
		add_spot(e, tab, size);
		return ;
	}
	if (!tab || ft_tablen((void**)tab) < 13)
		exit(ft_dprintf(2, "{red}error invalide elem in file{eoc}\n"));
	obj = ft_memalloc(sizeof(t_obj));
	obj->pos.x = ft_atof(tab[1]);
	obj->pos.y = ft_atof(tab[2]);
	obj->pos.z = ft_atof(tab[3]);
	obj->dir.x = ft_atof(tab[4]);
	obj->dir.y = ft_atof(tab[5]);
	obj->dir.z = ft_atof(tab[6]);
	obj->id = i;
	obj->r = ft_atof(tab[10]);
	obj->h = ft_atof(tab[11]);
	obj->color = ft_ahextocolor(tab[12]);
	obj->reflexion = ft_atof(tab[13]);
	select_type(tab, obj);
	e->tab_obj[i] = obj;
}

void	init_tab_obj(t_env *e, char *src)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;
	int		size[2];

	line = NULL;
	if ((fd = open(src, O_RDONLY)) <= 0)
		exit(ft_dprintf(2, "{red}error can't open file\n{eoc}"));
	get_next_line(fd, &line), tab = ft_strsplit(line, ' ');
	size[0] = ft_atoi(tab[0]);
	size[1] = ft_atoi(tab[1]);
	if (i = -1, !size[0] || !size[1])
		exit(ft_dprintf(2, "{red}error can't read sizes of file\n{eoc}"));
	e->tab_obj = ft_memalloc(sizeof(t_obj*) * (size[0] + 1));
	e->spots = ft_memalloc(sizeof(t_spot) * (size[1] + 1));
	while (get_next_line(fd, &line) > 0)
	{
		if ((tab = ft_strsplit(line, ' ')), tab && tab[0] && tab[0][0] != '#')
			add_obj_to_tab(e, tab, ++i, size);
		if (i > size[0])
			exit(ft_dprintf(2, "{red}error too many objs\n{eoc}"));
		ft_freetab(tab);
		free(line);
	}
}
