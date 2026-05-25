/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:44:12 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/25 15:02:37 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	checkchar(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0' &&
				cub->map[i][j] != 'N' && cub->map[i][j] != 'S' &&
				cub->map[i][j] != 'E' && cub->map[i][j] != 'W' &&
				cub->map[i][j] != '\n' && cub->map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	checkplayer(t_cub *cub, int total)
{
	int		i;
	int		j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' ||
				cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				cub->player_dir = cub->map[i][j];
<<<<<<< HEAD
				cub->map[i][j] = 0;
=======
				cub->map[i][j] = '0';
>>>>>>> origin/Raycasting
				cub->player_x = j;
				cub->player_y = i;
				total++;
			}
			j++;
		}
		i++;
	}
	if (total == 1)
		return (true);
	return (false);
}

bool	checkwallsbis(t_cub *cub, int i, int j)
{
	if ((i - 1) < 0 || !cub->map[i - 1] || !cub->map[i - 1][j] ||
		cub->map[i - 1][j] == ' ' || cub->map[i - 1][j] == '\n')
		return (false);
	if (!cub->map[i + 1] || !cub->map[i + 1][j] ||
		cub->map[i + 1][j] == ' ' || cub->map[i + 1][j] == '\n')
		return (false);
	if ((j - 1) < 0 || !cub->map[i][j - 1] ||
		cub->map[i][j - 1] == ' ' || cub->map[i][j - 1] == '\n')
		return (false);
	if (!cub->map[i][j + 1] || cub->map[i][j + 1] == ' ' ||
		cub->map[i][j + 1] == '\n')
		return (false);
	return (true);
}

bool	checkwalls(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
			{
				if (!checkwallsbis(cub, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	checkmap(int fdfile, t_cub *cub)
{
	if (!getmap(fdfile, cub))
		return (false);
	if (!checkchar(cub))
		return (false);
	if (!checkplayer(cub, 0))
		return (false);
	if (!checkwalls(cub))
		return (false);
	return (true);
}
