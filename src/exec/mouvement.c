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

void	move_forward_back(t_game *p, int keycode)
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

void	move_strafe(t_game *p, int keycode)
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

void	rotate(t_game *p, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed)
		- p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed)
		+ p->dir_y * cos(rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed)
		- p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed)
		+ p->plane_y * cos(rot_speed);
}