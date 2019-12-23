/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:44:38 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/24 19:45:45 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	error_msg(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		error_msg("Error: Bad input argument");
	else
	{
		if ((ft_strstr(argv[1], ".fdf")) == NULL)
			error_msg("Error: Filename");
		fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
		if (read_file(fdf, argv[1]) == 1)
			drawing(fdf, argv[1]);
	}
	error_msg("Magic error");
	return (0);
}
