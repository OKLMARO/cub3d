/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/25 15:14:11 by oamairi          ###   ########.fr       */
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
		cub->we_textures = ft_strdup(line + 3);
		if (!cub->we_textures)
			return (free(line), free(cub->no_textures),
				free(cub->so_textures), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "EA ", 3) && line[3])
		{
			line[ft_strlen(line) - 1] = 0;
			cub->ea_textures = ft_strdup(line + 3);
			if (!cub->ea_textures)
				return (free(line), free(cub->we_textures),
					free(cub->no_textures), free(cub->so_textures), false);
			return (free(line), true);
		}
		return (free(line), free(cub->we_textures), free(cub->no_textures),
			free(cub->so_textures), false);
	}
	return (free(line), free(cub->no_textures), free(cub->so_textures), false);
}

bool	checktexture(int fdfile, t_cub *cub)
{
	char	*line;

	line = get_next_line(fdfile);
	if (line && !ft_strncmp(line, "NO ", 3) && line[3])
	{
		line[ft_strlen(line) - 1] = 0;
		cub->no_textures = ft_strdup(line + 3);
		if (!cub->no_textures)
			return (free(line), false);
		free(line);
		line = get_next_line(fdfile);
		if (line && !ft_strncmp(line, "SO ", 3) && line[3])
		{
			line[ft_strlen(line) - 1] = 0;
			cub->so_textures = ft_strdup(line + 3);
			if (!cub->so_textures)
				return (free(line), free(cub->no_textures), false);
			free(line);
			return (checktexturebis(fdfile, cub));
		}
		return (free(line), free(cub->no_textures), false);
	}
	return (free(line), false);
}

bool	parsing(char *file, t_cub *cub)
{
	int	fdfile;

	ft_bzero(cub, sizeof(t_cub));
	cub->f[0] = -1;
	cub->c[0] = -1;
	if (!file || checknamefile(file) == false)
		return (ft_putendl_fd("Error\nFile name", 2), false);
	fdfile = open(file, O_RDONLY);
	if (fdfile == -1)
		return (ft_putendl_fd("Error\nOpen failed", 2), false);
	if (checktexture(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nTexture", 2), close(fdfile), false);
	free(get_next_line(fdfile));
	if (checkrgb(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nRGB", 2), close(fdfile), false);
	free(get_next_line(fdfile));
	if (checkmap(fdfile, cub) == false)
		return (ft_putendl_fd("Error\nMap", 2), close(fdfile), false);
	return (close(fdfile), true);
}
