/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:14:32 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 21:17:25 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		move_d(t_fdf *fdf)
{
	int		id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].y += STEP;
		id++;
	}
}

static void		move_u(t_fdf *fdf)
{
	int		id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].y -= STEP;
		id++;
	}
}

static void		move_l(t_fdf *fdf)
{
	int		id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].x -= STEP;
		id++;
	}
}

static void		move_r(t_fdf *fdf)
{
	int		id;

	id = 0;
	while (id < fdf->map->n_cords)
	{
		fdf->point[id].x += STEP;
		id++;
	}
}

void			move(int key, t_fdf *fdf)
{
	if (key == 123)
		move_l(fdf);
	if (key == 124)
		move_r(fdf);
	if (key == 125)
		move_d(fdf);
	if (key == 126)
		move_u(fdf);
}
