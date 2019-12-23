/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:26:45 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/24 19:12:32 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		gnl_for_points(int fd, t_map *m, t_p *p)
{
	int		id;
	int		id_x;
	int		id_y;
	char	*cords;

	id = 0;
	id_y = 0;
	while (get_next_line(fd, &cords) == 1)
	{
		id_x = 0;
		m->map = ft_strsplit(cords, ' ');
		while (m->map[id_x] != NULL)
		{
			p[id].x = (0 + id_x) * m->distance;
			p[id].y = (0 + id_y) * m->distance;
			p[id].z = (ft_atoi(m->map[id_x])) * m->distance;
			id_x++;
			id++;
		}
		free(cords);
		ft_arraydel(m->map);
		id_y++;
	}
	free(cords);
}

static t_p		*create_points(char *file_name, t_map *m, t_p *p)
{
	int		fd;
	int		id;

	id = 0;
	fd = open(file_name, O_RDONLY);
	gnl_for_points(fd, m, p);
	while (id < m->n_cords)
	{
		p[id].o_x = p[id].x;
		p[id].o_y = p[id].y;
		p[id].o_z = p[id].z;
		id++;
	}
	close(fd);
	return (p);
}

static void		gnl_for_map(int fd, t_map *m)
{
	char	*line;
	int		i;

	line = NULL;
	if (fd < 0 || (read(fd, line, 0)) < 0)
		error_msg("Error: Can't open file");
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		m->map = ft_strsplit(line, ' ');
		while (m->map[i] != NULL)
		{
			parsing(&m->map[i]);
			m->n_cords++;
			i++;
		}
		free(line);
		ft_arraydel(m->map);
		m->size_y++;
	}
	free(line);
}

static t_map	*create_map(char *file_name, t_map *m)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	m->size_x = 0;
	m->size_y = 0;
	m->n_cords = 0;
	gnl_for_map(fd, m);
	if (m->n_cords == 0)
		error_msg("Error: Empty file");
	m->size_x = m->n_cords / m->size_y;
	if (m->size_x <= 20)
		m->distance = 30;
	if (m->size_x > 20 && m->size_x <= 50)
		m->distance = 20;
	if (m->size_x > 50 && m->size_x <= 100)
		m->distance = 15;
	if (m->size_x > 100 && m->size_x <= 200)
		m->distance = 6;
	if (m->size_x > 200)
		m->distance = 3;
	close(fd);
	if (m->n_cords != m->size_x * m->size_y)
		error_msg("Error: Bad map size");
	return (m);
}

int				read_file(t_fdf *fdf, char *file_name)
{
	t_map		*m;
	t_p			*p;

	m = (t_map *)ft_memalloc(sizeof(t_map));
	m = create_map(file_name, m);
	p = (t_p *)ft_memalloc(sizeof(t_p) * m->n_cords);
	p = create_points(file_name, m, p);
	fdf->point = p;
	fdf->map = m;
	return (1);
}
