/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/03/16 17:12:07 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_minimap_background(t_game *game)
{
	int	y;
	int	x;

	y = MINIMAP_POSITIONY;
	while (y <= MINIMAP_POSITIONY + MINIMAP_HEIGHT)
	{
		x = MINIMAP_POSITIONX;
		while (x < MINIMAP_POSITIONX + MINIMAP_WIDTH)
		{
			put_pixel_canva(&game->scene, x, y, get_trgb(0, 32, 32, 28));
			x++;
		}
		y++;
	}
}

static void	draw_player_view(t_game *game)
{
	int		dest_x;
	int		dest_y;
	int		start;
	double	new[2];

	start = 30;
	while (start >= -30)
	{
		rotate_vector(game->player.delta, new, start);
		dest_x = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + (int)(new[X] * 600);
		dest_y = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + (int)(new[Y] * 600);
		draw_view_line(game, dest_x, dest_y);
		start--;
	}
}

void	update_minimap(t_game *game)
{
	draw_minimap_background(game);
	draw_minimap(game, draw_space, get_trgb(0, 230, 230, 230));
	draw_minimap(game, draw_walls, get_trgb(0, 32, 32, 28));
	draw_player_view(game);
}
