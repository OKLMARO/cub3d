/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:25:11 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/20 12:49:24 by oamairi          ###   ########.fr       */
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

bool	checkrgbf(int fdfile, t_cub *cub)
{
	int		i;
	int		j;
	int		temp;
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp("F ", line, 2) && line[2])
	{
		i = 2;
		j = 0;
		while (j < 3)
		{
			temp = addrgb(line, &i);
			if (temp == -1)
				return (free(line), false);
			cub->f[j] = temp;
			j++;
		}
		if (line[i] != '\n')
			return (free(line), false);
		return (free(line), true);
	}
	return (free(line), false);
}

bool	checkrgbc(int fdfile, t_cub *cub)
{
	int		i;
	int		j;
	int		temp;
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp("C ", line, 2) && line[2])
	{
		i = 2;
		j = 0;
		while (j < 3)
		{
			temp = addrgb(line, &i);
			if (temp == -1)
				return (free(line), false);
			cub->c[j] = temp;
			j++;
		}
		if (line[i] != '\n')
			return (free(line), false);
		return (free(line), true);
	}
	return (free(line), false);
}

bool	checkrgb(int fdfile, t_cub *cub)
{
	if (checkrgbf(fdfile, cub) == true)
	{
		if (checkrgbc(fdfile, cub) == true)
			return (true);
		return (false);
	}
	return (false);
}
