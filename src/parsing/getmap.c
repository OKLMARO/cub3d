/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:45:54 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static bool	getmaproutine(char *line, t_cub *cub)
{
	char	**temp;
	int		j;

	temp = malloc((cub->map_h + 2) * sizeof(char *));
	if (!temp)
		return (false);
	j = 0;
	while (j < cub->map_h)
	{
		temp[j] = cub->map[j];
		j++;
	}
	temp[j] = line;
	temp[j + 1] = NULL;
	free(cub->map);
	cub->map = temp;
	cub->map_h++;
	return (true);
}

static void	compute_map_w(t_cub *cub)
{
	int	i;
	int	len;

	cub->map_w = 0;
	i = 0;
	while (i < cub->map_h)
	{
		len = ft_strlen(cub->map[i]);
		if (len > cub->map_w)
			cub->map_w = len;
		i++;
	}
}

bool	getmap(int fdfile, t_cub *cub)
{
	char	*line;

	cub->map = NULL;
	cub->map_h = 0;
	line = get_next_line(fdfile);
	while (line)
	{
		if (!getmaproutine(line, cub))
			return (free(line), false);
		line = get_next_line(fdfile);
	}
	compute_map_w(cub);
	return (true);
}
