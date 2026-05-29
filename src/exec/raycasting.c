/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:02:54 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/29 22:11:03 by czinsou42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void	init_ray(t_game *p, t_ray *r, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_W - 1;
	r->dir_x = p->dir_x + p->plane_x * camera_x;
	r->dir_y = p->dir_y + p->plane_y * camera_x;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	if (r->dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->dir_y);
}


static void	init_step(t_game *g, t_ray *r)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->pos_x - r->map_x)
			* r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->pos_x)
			* r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->pos_y - r->map_y)
			* r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->pos_y)
			* r->delta_dist_y;
	}
}

void	run_dda(t_game *p, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_y < 0 || r->map_y >= p->cub.map_h
			|| r->map_x < 0 || r->map_x >= (int)ft_strlen(p->cub.map[r->map_y]))
			break ;
		if (p->cub.map[r->map_y][r->map_x] == '1')
			hit = 1;
	}
}

void	 set_wall_draw(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
	r->line_height = (int)(WIN_H / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}

void  raycasting(t_game *p)
{
    int     x;
    t_ray   r;

    x = 0;
    while (x < WIN_W)
    {
        init_ray(p, &r, x);
        init_step(p, &r);
        run_dda(p, &r);
        set_wall_draw(&r);
        draw_column(p, &r, x);
        x++;
    }
}

