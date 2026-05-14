/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:25:03 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/14 11:28:37 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB_H__
# define __CUB_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_cub
{
	int		C[3];
	int		F[3];
	char	**map;
	char	*NOtextures;
	char	*SOtextures;
	char	*WEtextures;
	char	*EAtextures;
}			t_cub;

void	free_double(char **tab_str);
bool	checkrgb(int fdfile, t_cub *cub);

#endif
