/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:27 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 12:56:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include <mlx.h>
# include "mlx_utils.h"
# include "map.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MINIMAP_WIDTH 300
# define MINIMAP_HEIGHT 150
# define MINIMAP_MARGIN 20
# define MINIMAP_SCALE 20

# define RAY_COLOR 16724787

# define X 0
# define Y 1

# define PI 3.1415926535f
# define SPEED 0.1f
# define A_SPEED 0.05f

typedef struct s_raycast {
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			lineheight;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			tex_x;
	int			tex_y;
	int			hit;
	int			side;
	int			c;
}	t_raycast;

typedef struct s_image	t_image;
typedef struct s_map	t_map;

typedef struct s_player
{
	double		position[2];
	double		plane[2];
	double		delta[2];
	double		angle;
}	t_player;

typedef struct s_game {
	void		*window;
	void		*mlx;
	t_map		map;
	t_image		scene;
	t_player	player;
	int			minimap_pos[2];
	t_image		textures[4];
	t_image		door[5];
	t_raycast	raycast;
	long		last;
	int			show_map;
	int			pause;
	int			padlock;
	int			d;
	long		door_time;
}	t_game;

typedef void	(*t_draw_walls)(t_game*, int[2], int, char);

void	draw_space(t_game *game, int vec[2], int color, char c);
void	draw_walls(t_game *game, int vec[2], int color, char c);
void	draw_door(t_game *game, int vec[2], int color, char c);
void	draw_minimap(t_game *game, t_draw_walls f, int color);
void	draw_view_line(t_game *game, int x1, int y1);
void	update_minimap(t_game *game);

void	move_player(int key, t_game *game);
void	move_vision(int key, t_game *game);
void	update_scene(t_game *game);
void	new_game(t_game *game);

double	perform_dda(t_game *game, int x);
void	init_calc(t_game *game, double c_x);
void	create_walls(t_game game, int x);
void	update_door(t_game *game);
void	set_texture(t_game *game);
void	do_steps(t_game *game);
void	raycast(t_game *game);

#endif