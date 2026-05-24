/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:24:49 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_cub(t_cub *cub)
{
	int	i;

	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->map)
	{
		i = 0;
		while (i < cub->map_h)
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
}
