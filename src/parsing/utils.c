/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:24:49 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/08 15:54:00 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_double(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str && tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}

void	free_cub(t_cub *cub)
{
	if (cub->line)
		free(cub->line);
	if (cub->map)
		free_double(cub->map);
	if (cub->no_textures)
		free(cub->no_textures);
	if (cub->so_textures)
		free(cub->so_textures);
	if (cub->we_textures)
		free(cub->we_textures);
	if (cub->ea_textures)
		free(cub->ea_textures);
}

void	updateline(t_cub *cub, int fdfile)
{
	if (cub->line)
		free(cub->line);
	cub->line = get_next_line(fdfile);
	while (cub->line && cub->line[0] == '\n')
	{
		free(cub->line);
		cub->line = get_next_line(fdfile);
	}
}

void	closegnl(int fdfile)
{
	char	*line;

	line = get_next_line(fdfile);
	while (line)
	{
		free(line);
		line = get_next_line(fdfile);
	}
	close(fdfile);
}
