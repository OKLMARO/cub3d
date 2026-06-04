/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/04 13:35:20 by oamairi          ###   ########.fr       */
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

bool	checktexturebis(t_cub *cub)
{
	if (cub->line && !ft_strncmp(cub->line, "WE ", 3)
		&& !ft_strncmp(cub->line + (ft_strlen(cub->line) - 5), ".xpm\n", 5))
	{
		cub->line[ft_strlen(cub->line) - 1] = 0;
		cub->we_textures = ft_strdup(cub->line + 3);
		if (!cub->we_textures)
			return (free(cub->line), free(cub->no_textures),
				free(cub->so_textures), false);
	}
	if (cub->line && !ft_strncmp(cub->line, "EA ", 3)
		&& !ft_strncmp(cub->line + (ft_strlen(cub->line) - 5), ".xpm\n", 5))
	{
		cub->line[ft_strlen(cub->line) - 1] = 0;
		cub->ea_textures = ft_strdup(cub->line + 3);
		if (!cub->ea_textures)
			return (free(cub->line), free_cub(cub), false);
		return (free(cub->line), true);
	}
	return (free(cub->line), false);
}

bool	checktexture(t_cub *cub)
{
	if (cub->line && !ft_strncmp(cub->line, "NO ", 3)
		&& !ft_strncmp(cub->line + (ft_strlen(cub->line) - 5), ".xpm\n", 5))
	{
		cub->line[ft_strlen(cub->line) - 1] = 0;
		cub->no_textures = ft_strdup(cub->line + 3);
		if (!cub->no_textures)
			return (free(cub->line), false);
		return (free(cub->line), true);
	}
	if (cub->line && !ft_strncmp(cub->line, "SO ", 3)
		&& !ft_strncmp(cub->line + (ft_strlen(cub->line) - 5), ".xpm\n", 5))
	{
		cub->line[ft_strlen(cub->line) - 1] = 0;
		cub->so_textures = ft_strdup(cub->line + 3);
		if (!cub->so_textures)
			return (free(cub->line), false);
		return (free(cub->line), true);
	}
	return (checktexturebis(cub));
}

bool	dispatch_parsing(t_cub *cub)
{
	if ()
}

bool	parsing(char *file, t_cub *cub)
{
	int	i;
	int	fdfile;

	ft_bzero(cub, sizeof(t_cub));
	cub->f[0] = -1;
	cub->c[0] = -1;
	if (!file || checknamefile(file) == false)
		return (ft_putendl_fd("Error\nFile name", 2), false);
	fdfile = open(file, O_RDONLY);
	if (fdfile == -1)
		return (ft_putendl_fd("Error\nOpen failed", 2), false);
	while (i < 6)
	{
		updateline(cub, fdfile);
		if (dispatch_parsing(cub) == false)
			return (closegnl(fdfile), false);
		i++;
	}
	return (closegnl(fdfile), true);
}
