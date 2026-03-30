/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:25:03 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/30 11:35:56 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB_H__
# define __CUB_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cub
{
	char	*NOtextures;
	char	*SOtextures;
	char	*WEtextures;
	char	*EAtextures;
	int		F[3];
	int		C[3]
}			;


#endif
