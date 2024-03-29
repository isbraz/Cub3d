/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:27 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:28:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "mlx_utils.h"
# include "raycast.h"
# include "map.h"

# define PI 3.1415926535f

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define X 0
# define Y 1

typedef struct s_raycast	t_raycast;
typedef struct s_image		t_image;
typedef struct s_map		t_map;

typedef struct s_player
{
	double		position[2];
	double		plane[2];
	double		delta[2];
	double		speed;
	double		angle;
}	t_player;

typedef struct s_doors
{
	t_image		door[5];
	long		time;
	int			index;
	int			lock;
}	t_doors;

typedef struct s_game {
	void		*window;
	void		*mlx;
	t_raycast	raycast;
	t_player	player;
	t_image		wall[4];
	t_doors		doors;
	t_image		scene;
	t_map		map;
	int			minimap_pos[2];
	long		last_mouse_move;
	int			show_map;
	int			pause;
}	t_game;

void	move_player(int key, t_game *game);
void	move_vision(int key, t_game *game);
void	update_scene(t_game *game);
void	new_game(t_game *game);

#endif