/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/01 17:06:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	checknamefile(char *file)
{
	int	i;

	if (!file)
		return (false);
	i = 0;
	while (file[i])
		i++;
	if (i < 4)
		return (false);
	if (!ft_strncmp(file + (i - 4), ".cub", 4))
		return (true);
	return (false);
}

bool	checktexture(int fdfile, t_cub *cub)
{
	char	*line;

	while ((line = get_next_line(fdfile)))
	{
		if (find_pos(line, cub) || find_posbis(line, cub))
		{
			free(line);
			continue;
		}
		cub->stash = line;
		return (true);
	}
	return (true);
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
