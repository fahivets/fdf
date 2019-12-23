/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:08:22 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/12/23 17:51:22 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define WIN_X 2000
# define WIN_Y 1000
# define STEP 3

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				rgb;
	double			o_x;
	double			o_y;
    double			o_z;
}					t_p;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	struct s_point	*point;
	struct s_map	*map;
	struct t_brez	*bresenham;
}					t_fdf;

typedef struct		s_map
{
	char			**map;
	int				size_x;
	int				size_y;
	int				n_cords;
	int				distance;
}					t_map;

typedef struct		s_bres
{
	double			dx;
	double			dy;
	double			l_x;
	double			l_y;
	int				len;
}					t_bres;

typedef struct		s_zoom
{
	double			z_x;
	double			z_y;
	double			z_z;
	double			x0;
	double			y0;
	double			z0;
	double			s;
}					t_zoom;

void				error_msg(char *str);
int					close_win(void *param);
int					read_file(t_fdf *fdf, char *file_name);
int					parsing(char **line);
void				drawing(t_fdf *fdf, char *file_name);
void				isometric(t_map *m, t_p *p);
void				go_centr(t_map *m, t_p *p);
void				reset_cords(t_fdf *fdf);
void				back_normal(t_fdf *fdf);
void				enable_drawing(t_fdf *fdf, t_map *m, t_p *p);
void				info(t_fdf *fdf);
int					enable_shift(int key, t_fdf *fdf);
void				shift(t_fdf *fdf);
void				rotation(int key, t_fdf *fdf);
void				move(int key, t_fdf *fdf);
void				zoom(int key, t_fdf *fdf);

#endif
