/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou42 <czinsou42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:30:32 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/15 22:33:13 by czinsou42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void	move_forward_back(t_game *p, int keycode)
{
	if (keycode == 119)
	{
		if (p->cub.map[(int)p->pos_y]
			[(int)(p->pos_x + p->dir_x * MOVE_SPEED)] != '1')
			p->pos_x += p->dir_x * MOVE_SPEED;
		if (p->cub.map[(int)(p->pos_y + p->dir_y * MOVE_SPEED)]
			[(int)p->pos_x] != '1')
			p->pos_y += p->dir_y * MOVE_SPEED;
	}
	if (keycode == 115)
	{
		if (p->cub.map[(int)p->pos_y]
			[(int)(p->pos_x - p->dir_x * MOVE_SPEED)] != '1')
			p->pos_x -= p->dir_x * MOVE_SPEED;
		if (p->cub.map[(int)(p->pos_y - p->dir_y * MOVE_SPEED)]
			[(int)p->pos_x] != '1')
			p->pos_y -= p->dir_y * MOVE_SPEED;
	}
}

static void	move_strafe(t_game *p, int keycode)
{
	if (keycode == 100)
	{
		if (p->cub.map[(int)p->pos_y]
			[(int)(p->pos_x + p->plane_x * MOVE_SPEED)] != '1')
			p->pos_x += p->plane_x * MOVE_SPEED;
		if (p->cub.map[(int)(p->pos_y + p->plane_y * MOVE_SPEED)]
			[(int)p->pos_x] != '1')
			p->pos_y += p->plane_y * MOVE_SPEED;
	}
	if (keycode == 97)
	{
		if (p->cub.map[(int)p->pos_y]
			[(int)(p->pos_x - p->plane_x * MOVE_SPEED)] != '1')
			p->pos_x -= p->plane_x * MOVE_SPEED;
		if (p->cub.map[(int)(p->pos_y - p->plane_y * MOVE_SPEED)]
			[(int)p->pos_x] != '1')
			p->pos_y -= p->plane_y * MOVE_SPEED;
	}
}

