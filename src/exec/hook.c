/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:25:21 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/15 13:29:30 by czinsou42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	close_game(t_game *p)
{
	mlx_destroy_image(p->mlx, p->img.ptr);
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	free_cub(&p->cub);
	exit(0);
	return (0);
}

int   key_hook(int keycode, t_game *p)
{
    if (keycode == 65307)
            close_game(p);
    else if (keycode == 119)
            move_fb(p, 1);
    else if (keycode == 115)
            move_fb(p, -1);
    else if (keycode == 97)
            move_strafe(p, -1);
    else if (keycode == 100)
            move_strafe(p, 1);
    else if (keycode == 65361)
            rotate(p, -ROT_SPEED);
    else if (keycode == 65363)
            rotate(p, ROT_SPEED);
    return (0);
}

void  setup_hooks(t_game *p)
{
    mlx_hook(p->win, 2, 1L << 0, key_hook, p);
    mlx_hook(p->win, 17, 0, close_game, p);
    mlx_loop_hook(p->mlx, game_loop, p);
    mlx_loop(p->mlx);
}