/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:40:03 by czinsou42         #+#    #+#             */
/*   Updated: 2026/05/25 15:22:36 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static int load_one_texture(t_game *p, int i, char *path)
{
    p->texture[i].ptr = mlx_xpm_file_to_image(p->mlx, path, &p->texture[i].width, &p->texture[i].height);
    if (!p->texture[i].ptr)
        return (0);
    p->texture[i].addr = mlx_get_data_addr(p->texture[i].ptr, &p->texture[i].bpp, &p->texture[i].line_len, &p->texture[i].endian);
    if (!p->texture[i].addr)
        return (0);
    return (1);
}

int load_all_textures(t_game *p)
{
    if (!load_one_texture(p, 0, p->cub.no_textures))
        return (0);
    if (!load_one_texture(p, 1, p->cub.so_textures))
        return (0);
    if (!load_one_texture(p, 2, p->cub.we_textures))
        return (0);
    if (!load_one_texture(p, 3, p->cub.ea_textures))
        return (0);
    return (1);
}