/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:39 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3D.h"

# define MINIMAP_WIDTH 300
# define MINIMAP_HEIGHT 150
# define MINIMAP_MARGIN 20
# define MINIMAP_SCALE 20

# define RAY_COLOR 16724787

typedef struct s_game	t_game;

typedef void			(*t_draw_walls)(t_game*, int[2], int, char);

void	draw_space(t_game *game, int vec[2], int color, char c);
void	draw_walls(t_game *game, int vec[2], int color, char c);
void	draw_door(t_game *game, int vec[2], int color, char c);
void	draw_minimap(t_game *game, t_draw_walls f, int color);
void	draw_view_line(t_game *game, int x1, int y1);
void	update_minimap(t_game *game);

#endif