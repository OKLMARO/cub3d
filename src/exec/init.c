/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void    set_player_orientation(t_game *p)
{
    if (p->cub.player_dir == 'N')
	{
		(p->dir_x = 0 , p->dir_y = -1);
		(p->plane_x = 0.66 , p->plane_y = 0);
	}
	else if (p->cub.player_dir == 'S')
	{
		(p->dir_x = 0 , p->dir_y = 1);
		(p->plane_x = -0.66 , p->plane_y = 0);
	}
    else if (p->cub.player_dir == 'E')
	{
		(p->dir_x = 1, p->dir_y = 0);
		(p->plane_x = 0 , p->plane_y = 0.66);
	}
	else if (p->cub.player_dir == 'W')
	{
		(p->dir_x = -1 , p->dir_y = 0);
		(p->plane_x = 0 , p->plane_y = -0.66);
	}
}
static void init_player(t_game *p)
{
    p->pos_x = p->cub.player_x + 0.5 ;
    p->pos_y = p->cub.player_y + 0.5 ;
    set_player_orientation(p) ;
}

static int init_img(t_game *p)
{
    p->img.ptr = mlx_new_image(p->mlx, WIN_W, WIN_H);
    if (!p->img.ptr)
        return (0);
    p->img.addr = mlx_get_data_addr(p->img.ptr, &p->img.bpp, &p->img.line_len, &p->img.endian);
    if (!p->img.addr)
        return(0);
    return(1);
}

int   init_game(t_game *p)
{
    p->mlx = mlx_init();
    if (!p->mlx)
        return (0);
    p->win = mlx_new_window(p->mlx, WIN_W, WIN_H, "Cub3d");
    if (!p->win)
        return (0);
    if (!init_img(p))
        return (0);
    init_player(p);
         return (1);
  }

