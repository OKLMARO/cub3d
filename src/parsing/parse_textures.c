/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static bool	set_texture(char *path, char **dest)
{
	if (*dest != NULL)
		return (false);
	*dest = ft_strtrim(path, " \t\n\r");
	if (!*dest || ft_strlen(*dest) == 0)
	{
		free(*dest);
		*dest = NULL;
		return (false);
	}
	return (true);
}

static bool	try_set_texture(char *line, t_cub *cub)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (set_texture(trimmed + 3, &cub->no));
	if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (set_texture(trimmed + 3, &cub->so));
	if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (set_texture(trimmed + 3, &cub->we));
	if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (set_texture(trimmed + 3, &cub->ea));
	return (false);
}

static bool	all_textures_set(t_cub *cub)
{
	return (cub->no && cub->so && cub->we && cub->ea);
}

bool	parse_textures(int fd, t_cub *cub)
{
	char	*line;

	while (!all_textures_set(cub))
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_putendl_fd("Error\nMissing texture", 2), false);
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (!try_set_texture(line, cub))
		{
			free(line);
			return (ft_putendl_fd("Error\nInvalid texture", 2), false);
		}
		free(line);
	}
	return (true);
}
