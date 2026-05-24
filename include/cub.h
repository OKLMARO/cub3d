/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:25:03 by oamairi           #+#    #+#             */
/*   Updated: 2026/05/16 00:06:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"


# define WIN_W 1280
# define WIN_H 720

#define MOVE_SPEED 0.10
#define ROT_SPEED 0.05

typedef struct s_ray
{
   double  dir_x;
   double  dir_y;
   double  delta_dist_x;
   double  delta_dist_y;
   double  side_dist_x;
   double  side_dist_y;
   double  perp_wall_dist;
   int     step_x;
   int     step_y;
   int     map_x;
   int     map_y;
   int     side;
   int     line_height;
   int     draw_start;
   int     draw_end;
} 			t_ray;

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

  typedef struct s_img
  {
      void    *ptr;
      char    *addr;
      int     bpp;
      int     line_len;
	  int     width;
      int     height;
      int     endian;
   }           t_img;

  typedef struct s_game
  {
      void    *mlx;
      void    *win;
      t_img   img;
	  t_img	  texture[4];	
      t_cub   cub;
      double  pos_x;
      double  pos_y;
      double  dir_x;
      double  dir_y;
      double  plane_x;
      double  plane_y;
  }           t_game;

// parsing
bool		parsing(char *file, t_cub *cub);
bool		checktexture(int fdfile, t_cub *cub);
bool		checktexturebis(int fdfile, t_cub *cub);
bool		checkrgb(int fdfile, t_cub *cub);
bool		checkmap(int fdfile, t_cub *cub);
bool		getmap(int fdfile, t_cub *cub);
bool		checkchar(t_cub *cub);
bool		checkplayer(t_cub *cub, int total);
bool		checkwalls(t_cub *cub);
bool		checkwallsbis(t_cub *cub, int i, int j);
void		free_cub(t_cub *cub);

// EXEC
int           init_game(t_game *game);
int           close_game(t_game *game);
int           key_hook(int keycode, t_game *game);
void		  setup_hooks(t_game *game);
int           load_all_textures(t_game *p);
void		run_dda(t_game *p, t_ray *r);
void	 	set_wall_draw(t_ray *r);
void  		 raycasting(t_game *p);
void  		draw_column(t_game *g, t_ray *r, int x);
void		move_forward_back(t_game *p, int keycode);
void		move_strafe(t_game *p, int keycode);
void		rotate(t_game *p, double rot_speed);
int   		game_loop(t_game *p);

#endif
