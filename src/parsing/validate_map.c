/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static bool	find_player(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->map_h)
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
				|| cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				if (cub->player_dir != 0)
					return (false);
				cub->player_dir = cub->map[y][x];
				cub->player_x = x;
				cub->player_y = y;
				cub->map[y][x] = '0';
			}
		}
	}
	return (cub->player_dir != 0);
}

static char	get_cell(t_cub *cub, int x, int y)
{
	if (y < 0 || y >= cub->map_h)
		return (' ');
	if (x < 0 || x >= (int)ft_strlen(cub->map[y]))
		return (' ');
	return (cub->map[y][x]);
}

static bool	check_cell_closed(t_cub *cub, int x, int y)
{
	if (get_cell(cub, x - 1, y) == ' ')
		return (false);
	if (get_cell(cub, x + 1, y) == ' ')
		return (false);
	if (get_cell(cub, x, y - 1) == ' ')
		return (false);
	if (get_cell(cub, x, y + 1) == ' ')
		return (false);
	return (true);
}

static bool	check_walls(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->map_h)
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == '0')
			{
				if (!check_cell_closed(cub, x, y))
					return (false);
			}
		}
	}
	return (true);
}

bool	validate_map(t_cub *cub)
{
	if (!find_player(cub))
		return (ft_putendl_fd("Error\nInvalid player position", 2), false);
	if (!check_walls(cub))
		return (ft_putendl_fd("Error\nMap not closed by walls", 2), false);
	return (true);
}
