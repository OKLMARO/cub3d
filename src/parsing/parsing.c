/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:50 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void	init_cub(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f[0] = -1;
	cub->f[1] = -1;
	cub->f[2] = -1;
	cub->c[0] = -1;
	cub->c[1] = -1;
	cub->c[2] = -1;
	cub->map = NULL;
	cub->map_h = 0;
	cub->map_w = 0;
	cub->player_dir = 0;
	cub->player_x = -1;
	cub->player_y = -1;
}

bool	check_filename(char *file)
{
	int	len;

	if (!file)
		return (false);
	len = ft_strlen(file);
	if (len < 5)
		return (false);
	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

static void	drain_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

bool	parsing(char *file, t_cub *cub)
{
	int	fd;

	init_cub(cub);
	if (!check_filename(file))
		return (ft_putendl_fd("Error\nInvalid file name", 2), false);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nCannot open file", 2), false);
	if (!parse_textures(fd, cub) || !parse_colors(fd, cub)
		|| !parse_map(fd, cub))
	{
		drain_gnl(fd);
		close(fd);
		free_cub(cub);
		return (false);
	}
	close(fd);
	if (!validate_map(cub))
	{
		free_cub(cub);
		return (false);
	}
	return (true);
}
