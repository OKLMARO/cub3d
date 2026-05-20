/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:45:54 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/20 12:46:22 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

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
