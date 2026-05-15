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