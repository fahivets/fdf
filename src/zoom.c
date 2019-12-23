/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:31:04 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 20:45:11 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		change_z(t_fdf *fdf, double c_z)
{
	int		id;
	double	i_x;
	double	i_y;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		i_x = fdf->point[id].x;
		i_y = fdf->point[id].y;
		fdf->point[id].z *= c_z;
		fdf->point[id].x = ((i_x - i_y) * cos(0.523599)) + (WIN_X / 2);
		fdf->point[id].y = ((i_x + i_y) * sin(0.523599)
				- fdf->point[id].z) + (WIN_Y / 2);
		id++;
	}
}

static void		make_zoom(t_fdf *fdf, t_zoom *z)
{
	int	id;

	id = 0;
	z->x0 = fdf->point[fdf->map->n_cords / 2 - fdf->map->size_x / 2].x;
	z->y0 = fdf->point[fdf->map->n_cords / 2 - fdf->map->size_x / 2].y;
	z->z0 = fdf->point[fdf->map->n_cords / 2 - fdf->map->size_x / 2].z;
	while (id < fdf->map->n_cords)
	{
		z->z_x = fdf->point[id].x;
		z->z_y = fdf->point[id].y;
		z->z_z = fdf->point[id].z;
		fdf->point[id].x = z->x0 + (z->z_x - z->x0) * z->s;
		fdf->point[id].y = z->y0 + (z->z_y - z->y0) * z->s;
		fdf->point[id].z = z->z0 + (z->z_z - z->z0) * z->s;
		id++;
	}
}

void			zoom(int key, t_fdf *fdf)
{
	t_zoom	z;
	double	c_z;

	if (key == 69)
	{
		z.s = 1.1;
		make_zoom(fdf, &z);
	}
	if (key == 78)
	{
		z.s = 0.9;
		make_zoom(fdf, &z);
	}
	if (key == 116)
	{
		c_z = 1.1;
		reset_cords(fdf);
		change_z(fdf, c_z);
	}
	if (key == 121)
	{
		c_z = 0.9;
		reset_cords(fdf);
		change_z(fdf, c_z);
	}
}
