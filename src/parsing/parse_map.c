/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_map_char(line[i]))
			return (false);
		i++;
	}
	return (i > 0);
}

static char	**realloc_map(char **map, char *line, int height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (height + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = ft_strtrim(line, "\n");
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

static bool	add_line_to_map(t_cub *cub, char *line)
{
	int	len;

	if (!is_valid_map_line(line))
		return (false);
	cub->map = realloc_map(cub->map, line, cub->map_h);
	if (!cub->map)
		return (false);
	len = ft_strlen(cub->map[cub->map_h]);
	if (len > cub->map_w)
		cub->map_w = len;
	cub->map_h++;
	return (true);
}

bool	parse_map(int fd, t_cub *cub)
{
	char	*line;
	bool	map_started;

	map_started = false;
	line = get_next_line(fd);
	while (line)
	{
		if (!map_started && is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (map_started && is_empty_line(line))
		{
			free(line);
			break ;
		}
		map_started = true;
		if (!add_line_to_map(cub, line))
			return (free(line),
				ft_putendl_fd("Error\nInvalid map line", 2), false);
		free(line);
		line = get_next_line(fd);
	}
	if (cub->map_h == 0)
		return (ft_putendl_fd("Error\nNo map found", 2), false);
	return (true);
}
