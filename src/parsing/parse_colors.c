/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static bool	valid_rgb_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (false);
	while (str[i] && str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\n' && str[i] != '\r')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	parse_rgb_values(char **split, int *rgb)
{
	int	i;
	int	val;

	i = 0;
	while (i < 3)
	{
		if (!split[i] || !valid_rgb_str(split[i]))
			return (false);
		val = ft_atoi(skip_spaces(split[i]));
		if (val < 0 || val > 255)
			return (false);
		rgb[i] = val;
		i++;
	}
	if (split[3])
		return (false);
	return (true);
}

bool	parse_color_line(char *line, int *rgb)
{
	char	**split;
	bool	ret;

	split = ft_split(line, ',');
	if (!split)
		return (false);
	ret = parse_rgb_values(split, rgb);
	ft_free_split(split);
	return (ret);
}

static bool	try_parse_color(char *line, t_cub *cub)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		if (cub->f[0] != -1)
			return (false);
		return (parse_color_line(skip_spaces(trimmed + 2), cub->f));
	}
	if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		if (cub->c[0] != -1)
			return (false);
		return (parse_color_line(skip_spaces(trimmed + 2), cub->c));
	}
	return (false);
}

bool	parse_colors(int fd, t_cub *cub)
{
	char	*line;

	while (cub->f[0] == -1 || cub->c[0] == -1)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_putendl_fd("Error\nMissing color", 2), false);
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (!try_parse_color(line, cub))
		{
			free(line);
			return (ft_putendl_fd("Error\nInvalid color", 2), false);
		}
		free(line);
	}
	return (true);
}
