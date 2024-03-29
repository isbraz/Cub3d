/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/03/29 13:45:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <minimap.h>

static void	draw_minimap_background(t_game *game)
{
	int	y;
	int	x;

	y = game->minimap_pos[Y];
	while (y <= game->minimap_pos[Y] + MINIMAP_HEIGHT)
	{
		x = game->minimap_pos[X];
		while (x < game->minimap_pos[X] + MINIMAP_WIDTH)
		{
			put_pixel(&game->scene, x, y, get_trgb(0, 32, 32, 28));
			x++;
		}
		y++;
	}
}

static void	draw_player_view(t_game *game)
{
	int		dest_x;
	int		dest_y;

	dest_x = game->minimap_pos[X] + (MINIMAP_WIDTH / 2) + \
							(int)(game->player.delta[X] * 600);
	dest_y = game->minimap_pos[Y] + (MINIMAP_HEIGHT / 2) + \
							(int)(game->player.delta[Y] * 600);
	draw_view_line(game, dest_x, dest_y);
}

void	update_minimap(t_game *game)
{
	if (!game->show_map)
		return ;
	draw_minimap_background(game);
	draw_minimap(game, draw_space, get_trgb(0, 230, 230, 230));
	draw_minimap(game, draw_walls, get_trgb(0, 32, 32, 28));
	draw_minimap(game, draw_door, get_trgb(0, 200, 0, 0));
	if (game->doors.lock)
		draw_minimap(game, draw_door, get_trgb(0, 0, 97, 0));
	draw_player_view(game);
}
