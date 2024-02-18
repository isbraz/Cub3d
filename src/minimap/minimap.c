/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/02/18 15:13:19 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_temp_obj(t_game *game, int y, int x, int color)
{
	int	temp_x;
	int	final_y;
	int	final_x;

	final_y = y + MINIMAP_SCALE;
	final_x = x + MINIMAP_SCALE;

	while (y < final_y && (y >= 0 && y < MINIMAP_HEIGHT))
	{
		temp_x = x;
		while (temp_x < final_x && (temp_x >= 0 && temp_x < MINIMAP_WIDTH))
			put_pixel_canva(&game->scene, (temp_x++) + MINIMAP_MARGIN, y + MINIMAP_POSITIONY, color);
		y++;
	}
}

static void	print_minimap_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			// print_temp_obj(game, ((y * MINIMAP_SCALE) - (game->player.position[Y] * MINIMAP_SCALE)),((x  * MINIMAP_SCALE) - (game->player.position[X] * MINIMAP_SCALE)), get_trgb(0, 255, 255, 255));
			if (is_floor(game->map.map[y][x]))
				print_temp_obj(game, ((y * MINIMAP_SCALE) + (MINIMAP_HEIGHT / 2) - (game->player.position[Y] * MINIMAP_SCALE)),
				((x * MINIMAP_SCALE) + (MINIMAP_WIDTH / 2) - (game->player.position[X] * MINIMAP_SCALE)), get_trgb(0, 230, 230 ,230));
			x++;
		}
		y++;
	}
}

static void	print_minimap_player(t_game *game)
{
	print_temp_obj(game, MINIMAP_HEIGHT / 2, MINIMAP_WIDTH / 2, get_trgb(0, 255, 50, 50));
}

static void print_minimap_background(t_game *game)
{
	int y;
	int x;

	y = MINIMAP_POSITIONY;
	while (y <= MINIMAP_POSITIONY + MINIMAP_HEIGHT)
	{
		x = MINIMAP_MARGIN;
		while (x < MINIMAP_WIDTH + MINIMAP_MARGIN)
		{
			put_pixel_canva(&game->scene, x, y, get_trgb(0, 28, 28, 28));
			x++;
		}
		y++;
	}
}

void	update_minimap(t_game *game)
{
	print_minimap_background(game);
	print_minimap_walls(game);
	print_minimap_player(game);
}
