/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:25:03 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/06 11:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB_H__
# define __CUB_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_cub
{
	int		c[3];
	int		f[3];
	char	**map;
	int		map_h;
	int		map_w;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	player_dir;
	int		player_x;
	int		player_y;
}			t_cub;

// parsing
bool	parsing(char *file, t_cub *cub);
bool	parse_textures(int fd, t_cub *cub);
bool	parse_colors(int fd, t_cub *cub);
bool	parse_map(int fd, t_cub *cub);
bool	validate_map(t_cub *cub);

// parsing utils
bool	check_filename(char *file);
bool	parse_color_line(char *line, int *rgb);
bool	is_empty_line(char *line);
char	*skip_spaces(char *str);
void	free_cub(t_cub *cub);
void	free_split(char **split);

#endif
