/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/03/15 12:38:06 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_minimap_square(t_game *game, int x, int y, int color)
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
			put_pixel_canva(&game->scene, \
			(temp_x++) + MINIMAP_POSITIONX, \
			y + MINIMAP_POSITIONY, \
			color);
		y++;
	}
}

static void	print_minimap_walls(t_game *game)
{
	int	y_middle;
	int	x_middle;
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			x_middle = (x * MINIMAP_SCALE) + (MINIMAP_WIDTH / 2);
			y_middle = (y * MINIMAP_SCALE) + (MINIMAP_HEIGHT / 2);
			if (is_floor(game->map.map[y][x]))
				print_minimap_square(game, \
				x_middle - (game->player.position[X] * MINIMAP_SCALE), \
				y_middle - (game->player.position[Y] * MINIMAP_SCALE), \
				get_trgb(0, 230, 230, 230));
			x++;
		}
		y++;
	}
}

static void	print_minimap_square2(t_game *game, int x, int y, int color)
{
	int	temp_x;
	int	final_y;
	int	final_x;

	final_y = y + 5;
	final_x = x + 5;
	while (y < final_y && (y >= 0 && y < MINIMAP_HEIGHT))
	{
		temp_x = x;
		while (temp_x < final_x && (temp_x >= 0 && temp_x < MINIMAP_WIDTH))
			put_pixel_canva(&game->scene, \
			(temp_x++) + MINIMAP_POSITIONX, \
			y + MINIMAP_POSITIONY, \
			color);
		y++;
	}
}

static void	print_minimap_player(t_game *game)
{
	print_minimap_square2(game, (MINIMAP_WIDTH / 2),
		(MINIMAP_HEIGHT / 2), get_trgb(0, 255, 50, 50));
}

static void	print_minimap_background(t_game *game)
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


/**
 * @brief	This function draw a line using Bresenham algorythm
 */
static void draw_line(t_game *game, int x1, int y1)
{
	int	err;
	int	e2;
	int	x0;
	int	y0;

	x0 = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + 2;
	y0 = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + 2;
	err = abs(x1 - x0) - abs(y1 - y0);
	while (x0 != x1 || y0 != y1)
	{
		if (get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 230, 230, 230) && \
				get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 255, 50, 50))
				break;
		put_pixel_canva(&game->scene, x0, y0, get_trgb(0, 255, 50, 50));
		e2 = 2 * err;
		if (e2 > -abs(y1 - y0))
		{
				err -= abs(y1 - y0);
				x0 += x0 < x1 ? 1 : -1;
		}
		if (e2 < abs(x1 - x0))
		{
				err += abs(x1 - x0);
				y0 += y0 < y1 ? 1 : -1;
		}
	}
}

static void	print_player_view(t_game *game)
{
	int		dest_x;
	int		dest_y;
	double	new_x;
	double	new_y;

	int start = 30;
	while (start >= -30)
	{
		new_x = game->player.pdx * cos(start*PI/180) - game->player.pdy * sin(start*PI/180);
		new_y = game->player.pdx * sin(start*PI/180) + game->player.pdy * cos(start*PI/180);
		dest_x = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + (int)(new_x * 600);
		dest_y = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + (int)(new_y * 600);
		draw_line(game, dest_x, dest_y);
		start--;
	}
}

void	update_minimap(t_game *game)
{
	print_minimap_background(game);
	print_minimap_walls(game);
	print_minimap_player(game);
	print_player_view(game);
}
