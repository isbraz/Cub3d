/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:55:34 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/16 17:16:37 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_minimap_square(t_game *game, int vec[2], int color, int size)
{
	int	temp_x;
	int	final_y;
	int	final_x;

	final_y = vec[Y] + size;
	final_x = vec[X] + size;
	while (vec[Y] < final_y && (vec[Y] >= 0 && vec[Y] < MINIMAP_HEIGHT))
	{
		temp_x = vec[X];
		while (temp_x < final_x && (temp_x >= 0 && temp_x < MINIMAP_WIDTH))
			put_pixel_canva(&game->scene, (temp_x++) + MINIMAP_POSITIONX, \
				vec[Y] + MINIMAP_POSITIONY, color);
		vec[Y]++;
	}
}

void	draw_space(t_game *game, int vec[2], int color, char c)
{
	if (is_floor(c))
		draw_minimap_square(game, vec, color, MINIMAP_SCALE + 1);
}

void	draw_walls(t_game *game, int vec[2], int color, char c)
{
	if (!is_floor(c))
		draw_minimap_square(game, vec, color, MINIMAP_SCALE + 1);
}

void	draw_minimap(t_game *game, t_draw_walls f, int color)
{
	int	middle[2];
	int	vec[2];
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			middle[X] = (x * MINIMAP_SCALE) + (MINIMAP_WIDTH / 2);
			middle[Y] = (y * MINIMAP_SCALE) + (MINIMAP_HEIGHT / 2);
			vec[X] = middle[X] - (game->player.position[X] * MINIMAP_SCALE);
			vec[Y] = middle[Y] - (game->player.position[Y] * MINIMAP_SCALE);
			f(game, vec, color, game->map.map[y][x]);
			x++;
		}
		y++;
	}
}
