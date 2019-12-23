/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:52:29 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/24 17:45:01 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		parsing(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i][j] != '\0')
		{
			if (line[i][j] == '-' || line[i][j] == '+')
				j++;
			if (line[i][j] == ',' && line[i][j + 1] == '0')
			{
				j++;
				break ;
			}
			if (ft_isdigit(line[i][j]) == 0)
				error_msg("Error: Found forbidden characters");
			j++;
		}
		i++;
	}
	return (1);
}
