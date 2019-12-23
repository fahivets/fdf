/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:21:12 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/30 21:27:33 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0x00FFFF, "-----INFO-----");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0x00FFFF, "I: isometric");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50,
			0x00FFFF, "P: parallel projection");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70,
			0x00FFFF, "Page Up/Down: change Z-cords");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0x00FFFF, "Backspace: reset");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0x00FFFF, "Z, X, C: rotation");
	mlx_string_put(fdf->mlx, fdf->win, 10, 130, 0x00FFFF, "+/-: zoom");
	mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0x00FFFF, "ESC:	exit");
}

void	shift(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, enable_shift, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_loop(fdf->mlx);
}

int		enable_shift(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 34)
	{
		back_normal(fdf);
		isometric(fdf->map, fdf->point);
	}
	if (key == 35)
	{
		reset_cords(fdf);
		go_centr(fdf->map, fdf->point);
	}
	if (key == 51)
	{
		back_normal(fdf);
		go_centr(fdf->map, fdf->point);
	}
	rotation(key, fdf);
	move(key, fdf);
	zoom(key, fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	info(fdf);
	enable_drawing(fdf, fdf->map, fdf->point);
	return (0);
}
