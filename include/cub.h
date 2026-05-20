/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:25:03 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/20 12:52:38 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_cub
{
	int		c[3];
	int		f[3];
	char	**map;
	int		player_x;
	int		player_y;
	char	player_dir;
	char	*no_textures;
	char	*so_textures;
	char	*we_textures;
	char	*ea_textures;
}			t_cub;

void	free_double(char **tab_str);
bool	getmap(int fdfile, t_cub *cub);
bool	checkrgb(int fdfile, t_cub *cub);
bool	checkmap(int fdfile, t_cub *cub);

#endif
