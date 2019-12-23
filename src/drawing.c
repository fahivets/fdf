/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:54:50 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/24 17:45:35 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	back_normal(t_fdf *fdf)
{
	int	id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].x = fdf->point[id].o_x;
		fdf->point[id].y = fdf->point[id].o_y;
		fdf->point[id].z = fdf->point[id].o_z;
		id++;
	}
}

void	reset_cords(t_fdf *fdf)
{
	int	id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].x = fdf->point[id].o_x;
		fdf->point[id].y = fdf->point[id].o_y;
		id++;
	}
}

void	go_centr(t_map *m, t_p *p)
{
	int		id;
	int		new_x;
	int		new_y;

	id = 0;
	new_x = (WIN_X / 2) - (p[m->size_x / 2].x);
	new_y = (WIN_Y / 2) - (p[(m->n_cords) / 2].y);
	while (id < m->n_cords)
	{
		p[id].x += new_x;
		p[id].y += new_y;
		id++;
	}
}

void	isometric(t_map *m, t_p *p)
{
	int		id;
	double	i_x;
	double	i_y;

	id = 0;
	while (id < m->n_cords)
	{
		i_x = p[id].x;
		i_y = p[id].y;
		p[id].x = ((i_x - i_y) * cos(0.523599)) + (WIN_X / 2);
		p[id].y = ((i_x + i_y) * sin(0.523599) - p[id].z) + (WIN_Y / 2);
		id++;
	}
}

void	drawing(t_fdf *fdf, char *file_name)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, file_name);
	go_centr(fdf->map, fdf->point);
	info(fdf);
	enable_drawing(fdf, fdf->map, fdf->point);
	shift(fdf);
}
