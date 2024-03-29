/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:27 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 12:11:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>

# include <mlx.h>

# include "mlx_utils.h"
# include "utils.h"


# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MINIMAP_WIDTH 300
# define MINIMAP_HEIGHT 150
# define MINIMAP_MARGIN 20
# define MINIMAP_SCALE 20

# define RAY_COLOR 16724787

# define INVALID_TYPE 6
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

# define X 0
# define Y 1

# define ARGUMENTS_ERROR 400
# define OPENING_ERROR 401
# define BREAKS_ERROR 402
# define SPAWN_ERROR 403
# define TYPES_ERROR 404
# define WALL_ERROR 405
# define PI 3.1415926535f
# define SPEED 0.1f
# define A_SPEED 0.05f

typedef struct s_image
{
	void		*id;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_image;

typedef struct s_player
{
	double		position[2];
	double		plane[2];
	double		delta[2];
	double		angle;
}	t_player;

typedef struct s_map {
	char		*types_info[6];
	int			ceiling_color;
	int			floor_color;
	char		**types;
	char		*input;
	char		**map;
	int			map_start;
	char		spawn_dir;
	double		spawn_pos[2];
	int			minimap_pos[2];
}	t_map;

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

typedef struct s_game {
	void		*window;
	void		*mlx;
	t_map		map;
	t_image		scene;
	t_player	player;
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

void	exit_parsing_error(t_map *map, int status);
void	get_map(t_map *map, char *argv[]);
void	free_map(t_map *map);
void	verify_map(t_map *map);
int		verify_breaks(t_map *map);
int		verify_walls(t_map *map);
int		get_types(t_map *map);
int		get_spawn(t_map *map);

void	draw_view_line(t_game *game, int x1, int y1);
void	update_minimap(t_game *game);
void	draw_minimap(t_game *game, t_draw_walls f, int color);
void	draw_space(t_game *game, int vec[2], int color, char c);
void	draw_walls(t_game *game, int vec[2], int color, char c);
void	draw_door(t_game *game, int vec[2], int color, char c);

void	update_scene(t_game *game);
void	new_game(t_game *game);

void	raycast(t_game *game);
void	init_calc(t_game *game, double c_x);
void	do_steps(t_game *game);
void	move_player(int key, t_game *game);
void	move_vision(int key, t_game *game);
void	update_door(t_game *game);
double	perform_dda(t_game *game, int x);
void	set_texture(t_game *game);
void	create_walls(t_game game, int x);

#endif