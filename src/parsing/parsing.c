/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/04/08 14:48:58 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	checknamefile(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		return (false);
	if (!ft_strncmp(file + i, "cub", 3))
		return (true);
	return (false);
}

bool	checktexturebis(int fdfile, t_cub *cub)
{
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp(line, "WE", 2) && (line + 3))
	{
		cub->WEtextures = ft_strdup(line + 3);
		if (!cub->WEtextures)
			return (free(line), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "EA", 2) && (line + 3))
		{
			cub->EAtextures = ft_strdup(line + 3);
			if (!cub->EAtextures)
				return (free(line), false);
			return (free(line), true);
		}
		return (free(line), false);
	}
	return (free(line), false);
}

bool	checktexture(int fdfile, t_cub *cub)
{
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp(line, "NO", 2))
	{
		cub->NOtextures = ft_strdup(line + 3);
		if (!cub->NOtextures)
			return (free(line), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "SO", 2) && (line + 3))
		{
			cub->SOtextures = ft_strdup(line + 3);
			if (!cub->SOtextures)
				return (free(line), false);
			free(line);
			return (checktexturebis(fdfile, cub));
		}
		return (free(line), false);
	}
	return (free(line), false);
}

bool	checkflourbis(t_cub *cub, char *line, char *rgb[], int i)
{
	int	j;

	j = i + 2;
	i = 0;
	while (line[i + j] && (i > 3 || line[i + j] == ',')
		&& ft_isdigit(line[i + j]))
	{
		rgb[i] = line[i + j];
		i++;
	}
	if (i == 0 && line[i + j] == ',')
		return (free(line), false);
	j = i + j;
	i = 0;
	while (line[i + j] && (i > 3 || line[i + j] == ',')
		&& ft_isdigit(line[i + j]))
	{
		rgb[i] = line[i + j];
		i++;
	}
	if (i == 0 && line[i + j] == ',')
		return (free(line), false);
	return (true);
}

bool	checkflour(int fdfile, t_cub *cub)
{
	int		i;
	int		j;
	char	*line;
	char	rgb[3];

	line = get_next_line(fdfile);
	if (line && !ft_strncmp("F ", line, 2) && (line + 2))
	{
		i = 0;
		j = 2;
		while (line[i + j] && (i > 3 || line[i + j] == ',')
			&& ft_isdigit(line[i + j]))
		{
			rgb[i] = line[i + j];
			i++;
		}
		if (i == 0 && line[i + j] == ',')
			return (free(line), false);
		return (free(line), checkrgbthird(cub, line, &rgb, i));
	}
	return (free(line), false);
}

bool	checkrgb(int fdfile, t_cub *cub)
{
	if (checkrgbsecond(fdfile, cub, "F ") == true)
	{
		if (checkrgbsecond(fdfile, cub, "C ") == true)
			return (true);
		return (false);
	}
	return (false);
}

bool	parsing(char *file, t_cub *cub)
{
	int	fdfile;

	if (!file || checknamefile(file) == false)
		return (ft_putendl_fd("Error\nFile name", 2), false);
	fdfile = open(file, O_RDONLY);
	if (fdfile == -1)
		return (ft_putendl_fd("Error\nOpen failed", 2), false);
	if (checktexture(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nTexture", 2), false);
	free(get_next_line(fdfile));
	if (checkrgb(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nRGB", 2), false);
	close(fdfile);
}
