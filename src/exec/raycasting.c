/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:02:54 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/15 17:20:17 by czinsou42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void	init_ray(t_game *g, t_ray *r, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_W - 1;
	r->dir_x = g->dir_x + g->plane_x * camera_x;
	r->dir_y = g->dir_y + g->plane_y * camera_x;

	r->map_x = (int)g->pos_x;
	r->map_y = (int)g->pos_y;

	if (r->dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->dir_x);

	if (r->dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->dir_y);
}