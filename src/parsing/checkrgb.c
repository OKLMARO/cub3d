/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:25:11 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/09 13:24:58 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	addrgb(char *line, int *i)
{
	int		k;
	char	rgb[4];

	k = 0;
	ft_bzero(rgb, 4);
	while (k < 3 && ft_isdigit(line[*i + k]))
	{
		rgb[k] = line[*i + k];
		k++;
	}
	if (line[*i + k] == ',')
	{
		if (k == 0)
			return (-1);
		*i = *i + 1;
	}
	else if (k == 0 || (ft_isdigit(line[*i + k]) && k == 3))
		return (-1);
	if (ft_atoi(rgb) < 256 && ft_atoi(rgb) >= 0)
	{
		*i = *i + k;
		return (ft_atoi(rgb));
	}
	return (-1);
}

bool	checkrgbf(t_cub *cub)
{
	int		i;
	int		j;
	int		temp;

	if (cub->line && !ft_strncmp("F ", cub->line, 2) && cub->line[2])
	{
		i = 2;
		j = 0;
		while (j < 3)
		{
			temp = addrgb(cub->line, &i);
			if (temp == -1)
				return (ft_putendl_fd("Error\nRGB", 2), false);
			cub->f[j] = temp;
			j++;
		}
		if (cub->line[i] != '\n' || cub->line[i - 1] == ',')
			return (ft_putendl_fd("Error\nRGB", 2), false);
		return (true);
	}
	return (false);
}

bool	checkrgbc(t_cub *cub)
{
	int		i;
	int		j;
	int		temp;

	if (cub->line && !ft_strncmp("C ", cub->line, 2) && cub->line[2])
	{
		i = 2;
		j = 0;
		while (j < 3)
		{
			temp = addrgb(cub->line, &i);
			if (temp == -1)
				return (ft_putendl_fd("Error\nRGB", 2), false);
			cub->c[j] = temp;
			j++;
		}
		if (cub->line[i] != '\n' || cub->line[i - 1] == ',')
			return (ft_putendl_fd("Error\nRGB", 2), false);
		return (true);
	}
	return (false);
}

bool	checkrgb(t_cub *cub)
{
	if (checkrgbf(cub) == true)
		return (true);
	if (checkrgbc(cub) == true)
		return (true);
	return (false);
}
