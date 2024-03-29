/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:36:32 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3D.h"
# include <math.h>

typedef struct s_raycast {
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		lineheight;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		tex_x;
	int		tex_y;
	int		hit;
	int		side;
	int		c;
}	t_raycast;

double	perform_dda(t_game *game, int x);
void	init_calc(t_game *game, double c_x);
void	create_walls(t_game game, int x);
void	update_door(t_game *game);
void	set_texture(t_game *game);
void	do_steps(t_game *game);
void	raycast(t_game *game);

#endif