/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:52:12 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 21:13:51 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		rotate_x(t_fdf *fdf, double r)
{
	int		id;
	double	r_y;
	double	r_z;
	double	y0;
	double	z0;

	id = 0;
	y0 = fdf->point[fdf->map->n_cords / 2].y;
	z0 = fdf->point[fdf->map->n_cords / 2].z;
	while (id < fdf->map->n_cords)
	{
		r_y = fdf->point[id].y;
		r_z = fdf->point[id].z;
		fdf->point[id].y = y0 + (r_y - y0) * cos(r) + (z0 - r_z) * sin(r);
		fdf->point[id].z = z0 + (r_y - y0) * sin(r) + (r_z - z0) * cos(r);
		id++;
	}
}

static void		rotate_y(t_fdf *fdf, double r)
{
	int		id;
	double	r_x;
	double	r_z;
	double	x0;
	double	z0;

	id = 0;
	x0 = fdf->point[fdf->map->n_cords / 2].x;
	z0 = fdf->point[fdf->map->n_cords / 2].z;
	while (id < fdf->map->n_cords)
	{
		r_x = fdf->point[id].x;
		r_z = fdf->point[id].z;
		fdf->point[id].x = x0 + (r_x - x0) * cos(r) + (r_z - z0) * sin(r);
		fdf->point[id].z = z0 + (x0 - r_x) * sin(r) + (r_z - z0) * cos(r);
		id++;
	}
}

static void		rotate_z(t_fdf *fdf, double r)
{
	int		id;
	double	r_x;
	double	r_y;
	double	x0;
	double	y0;

	id = 0;
	x0 = fdf->point[fdf->map->n_cords / 2].x;
	y0 = fdf->point[fdf->map->n_cords / 2].y;
	while (id < fdf->map->n_cords)
	{
		r_x = fdf->point[id].x;
		r_y = fdf->point[id].y;
		fdf->point[id].x = x0 + (r_x - x0) * cos(r) + (y0 - r_y) * sin(r);
		fdf->point[id].y = y0 + (r_x - x0) * sin(r) + (r_y - y0) * cos(r);
		id++;
	}
}

void			rotation(int key, t_fdf *fdf)
{
	double	r;

	r = 0.174533;
	if (key == 6)
		rotate_x(fdf, r);
	if (key == 7)
		rotate_y(fdf, r);
	if (key == 8)
		rotate_z(fdf, r);
}
