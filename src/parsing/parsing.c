/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/13 15:30:33 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	checknamefile(char *nameFile)
{
	int	i;

	i = ft_strlen(nameFile) - 1;
	while (i > 0 && nameFile[i] != '.')
		i--;
	if (!ft_strncmp(nameFile + i, ".cub", 4) && !nameFile[i + 4])
		return (true);
	return (false);
}

bool	checktexturebis(int fdfile, t_cub *cub)
{
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp(line, "WE ", 3) && line[3])
	{
		line[ft_strlen(line) - 1] = 0;
		cub->WEtextures = ft_strdup(line + 3);
		if (!cub->WEtextures)
			return (free(line), free(cub->NOtextures),
				free(cub->SOtextures), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "EA ", 3) && line[3])
		{
			line[ft_strlen(line) - 1] = 0;
			cub->EAtextures = ft_strdup(line + 3);
			if (!cub->EAtextures)
				return (free(line), free(cub->WEtextures),
					free(cub->NOtextures), free(cub->SOtextures), false);
			return (free(line), true);
		}
		return (free(line), free(cub->WEtextures), free(cub->NOtextures),
			free(cub->SOtextures), false);
	}
	return (free(line), free(cub->NOtextures), free(cub->SOtextures), false);
}

bool	checktexture(int fdfile, t_cub *cub)
{
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp(line, "NO ", 3) && line[3])
	{
		line[ft_strlen(line) - 1] = 0;
		cub->NOtextures = ft_strdup(line + 3);
		if (!cub->NOtextures)
			return (free(line), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "SO ", 3) && line[3])
		{
			line[ft_strlen(line) - 1] = 0;
			cub->SOtextures = ft_strdup(line + 3);
			if (!cub->SOtextures)
				return (free(line), free(cub->NOtextures), false);
			free(line);
			return (checktexturebis(fdfile, cub));
		}
		return (free(line), free(cub->NOtextures), false);
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

bool	checkrgbf(int fdfile, t_cub *cub)
{
	int		i;
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp("F ", line, 2) && line[2])
	{
		i = 2;
		
	}
}

bool	checkrgb(int fdfile, t_cub *cub)
{
	if (checkrgbf(fdfile, cub) == true)
	{
		if (checkrgbsc(fdfile, cub) == true)
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
		return (ft_putendl_fd("Error\nTexture", 2), close(fdfile), false);
	free(get_next_line(fdfile));
	if (checkrgb(fdfile, cub) == false)
	return (close(fdfile), true);
	return (ft_putendl_fd("Error\nRGB", 2), close(fdfile), false);
}
