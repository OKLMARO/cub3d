/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:26:40 by marvin            #+#    #+#             */
/*   Updated: 2026/05/01 15:26:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool    find_pos(char *line, t_cub *cub)
{
    char	*tmp;

	if (!line)
		return (false);

	if (!ft_strncmp(line, "WE ", 3))
	{
		if (cub->WEtextures)
			return (false);
		tmp = ft_strdup(line + 3);
		if (!tmp)
			return (false);
		cub->WEtextures = tmp;
		return (true);
	}
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (cub->NOtextures)
			return (false);
		tmp = ft_strdup(line + 3);
		if (!tmp)
			return (false);
		cub->NOtextures = tmp;
		return (true);
	}
    return (false);
}

bool    find_posbis(char *line, t_cub *cub)
{
    char    *tmp;

    if (!line)
        return (false);
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (cub->SOtextures)
			return (false);
		tmp = ft_strdup(line + 3);
		if (!tmp)
			return (false);
		cub->SOtextures = tmp;
		return (true);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (cub->EAtextures)
			return (false);
		tmp = ft_strdup(line + 3);
		if (!tmp)
			return (false);
		cub->EAtextures = tmp;
		return (true);
	}
	return (false);
}

bool	parse_texture(char *line, t_cub *cub)
{
	if (!line)
		return (false);

	if (find_pos(line, cub))
        return (true);
    if (find_posbis(line, cub))
        return (true);
	return (false);
}