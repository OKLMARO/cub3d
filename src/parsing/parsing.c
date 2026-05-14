/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/14 13:05:45 by oamairi          ###   ########.fr       */
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

bool	getmaproutine(char *line, t_cub *cub, int i)
{
	int		j;
	char	**temp;

	temp = malloc((i + 1) * sizeof(char *));
	if (!temp)
		return (false);
	j = 0;
	while (j < i)
	{
		if (cub->map)
			temp[j] = cub->map[j];
		j++;
	}
	temp[j] = line;
	temp[j + 1] = NULL;
	if (cub->map)
		free(cub->map);
	cub->map = temp;
	return (true);
}

bool	getmap(int fdfile, t_cub *cub)
{
	int		i;
	char	*line;

	cub->map = NULL;
	i = 1;
	line = get_next_line(fdfile);
	while (line)
	{
		if (!getmaproutine(line, cub, i))
			return (free(line), false);
		i++;
		line = get_next_line(fdfile);
	}
	return (true);
}

bool	checkchar(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' &&
				cub->map[i][j] != 'N' && cub->map[i][j] != 'S' &&
				cub->map[i][j] != 'E' && cub->map[i][j] != 'W' &&
				cub->map[i][j] != '\n' && cub->map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	checkmap(int fdfile, t_cub *cub)
{
	if (!getmap(fdfile, cub))
		return (false);
	if (!checkchar(cub))
		return (false);
	return (true);
}

bool	parsing(char *file, t_cub *cub)
{
	int	fdfile;

	if (!file || checknamefile(file) == false)
		return (ft_putendl_fd("Error\nFile name", 1), false);
	fdfile = open(file, O_RDONLY);
	if (fdfile == -1)
		return (ft_putendl_fd("Error\nOpen failed", 1), false);
	if (checktexture(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nTexture", 1), close(fdfile), false);
	free(get_next_line(fdfile));
	if (checkrgb(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nRGB", 1), close(fdfile), false);
	free(get_next_line(fdfile));
	if (checkMap(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nMap", 1), close(fdfile), false);
	return (close(fdfile), true);
}
