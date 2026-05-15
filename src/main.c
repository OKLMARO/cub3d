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

int   game_loop(t_game *p)
{
    raycasting(p);
    mlx_put_image_to_window(p->mlx, p->win, p->img.ptr, 0, 0);
    return (0);
}

int   main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
    {
        printf("Error\nUsage: ./cub3d <file.cub>\n");
            return (1);
    }
    if (!parsing(av[1], &game.cub))
        return (1);
    if (!init_game(&game))
        return (1);
    if (!load_textures(&game))
        return (1);
    setup_hooks(&game);
    return (0);
}
