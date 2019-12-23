/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:35:41 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 21:20:30 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**/
#include "../inc/fdf.h"

static void		bres_x(t_fdf *fdf, t_bres *b, double b_x, double b_y)
{
	double	d;

	d = -b->l_x;
	b->len++;
	while (b->len--)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, b_x, b_y, 0xFF0000);
		b_x += b->dx;
		d += 2 * b->l_y;
		if (d > 0)
		{
			d -= 2 * b->l_x;
			b_y += b->dy;
		}
	}
}

static void		bres_y(t_fdf *fdf, t_bres *b, double b_x, double b_y)
{
	double	d;

	d = -b->l_y;
	b->len++;
	while (b->len--)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, b_x, b_y, 0xFF0000);
		b_y += b->dy;
		d += 2 * b->l_x;
		if (d > 0)
		{
			d -= 2 * b->l_y;
			b_x += b->dx;
		}
	}
}

static void		bresenham(t_fdf *fdf, t_p p1, t_p p2)
{
	t_bres		b;
	double		b_x;
	double		b_y;

	b.dx = (p2.x - p1.x >= 0 ? 1 : -1);
	b.dy = (p2.y - p1.y >= 0 ? 1 : -1);
	b.l_x = fabs(p2.x - p1.x);
	b.l_y = fabs(p2.y - p1.y);
	b.len = b.l_x > b.l_y ? b.l_x : b.l_y;
	b_x = p1.x;
	b_y = p1.y;
	mlx_pixel_put(fdf->mlx, fdf->win, p2.x, p2.y, 0xFF0000);
	if ((b.l_x - b.l_y) == 0)
		mlx_pixel_put(fdf->mlx, fdf->win, p1.x, p1.y, 0xFF0000);
	if (b.l_y <= b.l_x)
		bres_x(fdf, &b, b_x, b_y);
	else
		bres_y(fdf, &b, b_x, b_y);
}

void			enable_drawing(t_fdf *fdf, t_map *m, t_p *p)
{
	int		x;
	int		y;
	int		row;

	y = 0;
	while (y < m->size_y)
	{
		x = 0;
		row = y * m->size_x;
		while (x < m->size_x)
		{
			if (x != m->size_x - 1)
				bresenham(fdf, p[x + row], p[x + row + 1]);
			if (y != m->size_y - 1)
				bresenham(fdf, p[x + row], p[x + row + m->size_x]);
			x++;
		}
		y++;
	}
}
