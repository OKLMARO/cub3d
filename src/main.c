/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	printf("Map (%dx%d):\n", cub->map_w, cub->map_h);
	while (i < cub->map_h)
	{
		printf("  [%s]\n", cub->map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		printf("Usage: ./cub3d <file.cub>\n");
		return (1);
	}
	if (!parsing(av[1], &cub))
		return (1);
	printf("=== Parsing OK ===\n");
	printf("NO: %s\n", cub.no);
	printf("SO: %s\n", cub.so);
	printf("WE: %s\n", cub.we);
	printf("EA: %s\n", cub.ea);
	printf("F:  %d,%d,%d\n", cub.f[0], cub.f[1], cub.f[2]);
	printf("C:  %d,%d,%d\n", cub.c[0], cub.c[1], cub.c[2]);
	printf("Player: %c at (%d, %d)\n",
		cub.player_dir, cub.player_x, cub.player_y);
	print_map(&cub);
	free_cub(&cub);
	return (0);
}
