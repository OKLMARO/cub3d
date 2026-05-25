/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:32:25 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/15 18:34:16 by czinsou42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

 static void   put_pixel(t_game *g, int x, int y, int color)
{
     int     offset;

    offset = y * g->img.line_len + x * (g->img.bpp / 8);
    *(unsigned int *)(g->img.addr + offset) = color;
}


static int    get_tex_color(t_img *tex, int x, int y)
{
    int     offset;

    offset = y * tex->line_len + x * (tex->bpp / 8);
    return (*(unsigned int *)(tex->addr + offset));
}

static t_img  *choose_texture(t_game *g, t_ray *r)
{
    if (r->side == 0 && r->dir_x < 0)
        return (&g->texture[2]);
    else if (r->side == 0 && r->dir_x > 0)
        return (&g->texture[3]);
    else if (r->side == 1 && r->dir_y < 0)
        return (&g->texture[0]);
    return (&g->texture[1]);
}

static void   draw_wall(t_game *g, t_ray *r, int x)
{
    t_img   *tex;
    double  step;
    double  tex_pos;
    int             tex_x;
    int             y;

    tex = choose_texture(g, r);
    if (r->side == 0)
            tex_x = (int)((g->pos_y + r->perp_wall_dist
                                    * r->dir_y - floor(g->pos_y + r->perp_wall_dist
                                            * r->dir_y)) * tex->width);
    else
            tex_x = (int)((g->pos_x + r->perp_wall_dist
                                    * r->dir_x - floor(g->pos_x + r->perp_wall_dist
                                            * r->dir_x)) * tex->width);
    step = (double)tex->height / r->line_height;
    tex_pos = (r->draw_start - WIN_H / 2
                    + r->line_height / 2) * step;
    y = r->draw_start;
    while (y < r->draw_end)
    {
            put_pixel(g, x, y, get_tex_color(tex, tex_x, (int)tex_pos));
            tex_pos += step;
            y++;
    }
}

void  draw_column(t_game *g, t_ray *r, int x)
{
    int     y;
    int     c_color;
    int     f_color;

    c_color = (g->cub.c[0] << 16) | (g->cub.c[1] << 8) | g->cub.c[2];
    f_color = (g->cub.f[0] << 16) | (g->cub.f[1] << 8) | g->cub.f[2];
    y = 0;
    while (y < r->draw_start)
    {
            put_pixel(g, x, y, c_color);
            y++;
    }
    draw_wall(g, r, x);
    y = r->draw_end;
    while (y < WIN_H)
    {
            put_pixel(g, x, y, f_color);
            y++;
    }
}
