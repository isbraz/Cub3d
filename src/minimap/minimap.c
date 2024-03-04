/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/03/04 15:15:51 by isbraz-d         ###   ########.fr       */
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
	while (y < final_y - 1 && (y >= 0 && y < MINIMAP_HEIGHT))
	{
		temp_x = x;
		while (temp_x < final_x - 1 && (temp_x >= 0 && temp_x < MINIMAP_WIDTH))
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
	while (y < final_y - 1 && (y >= 0 && y < MINIMAP_HEIGHT))
	{
		temp_x = x;
		while (temp_x < final_x - 1 && (temp_x >= 0 && temp_x < MINIMAP_WIDTH))
			put_pixel_canva(&game->scene, \
			(temp_x++) + MINIMAP_POSITIONX, \
			y + MINIMAP_POSITIONY, \
			color);
		y++;
	}
}

static void	print_minimap_player(t_game *game)
{
	print_minimap_square2(game, (MINIMAP_WIDTH / 2) +10,
		(MINIMAP_HEIGHT / 2)+10, get_trgb(0, 255, 50, 50));
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
static void draw_line(t_game *game, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
		//call dda function
        put_pixel_canva(&game->scene, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}



static void	print_player_view(t_game *game)
{
	int	player_x;
	int	player_y;
	int	dest_x;
	int	dest_y;

	player_x = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2);
	player_y = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2);
	dest_x = player_x + (int)(game->player.pdx * MINIMAP_SCALE);
	dest_y = player_y + (int)(game->player.pdy * MINIMAP_SCALE);
	draw_line(game, player_x + 10, player_y + 10, dest_x, dest_y, get_trgb(0, 255, 50, 50));
}

void	update_minimap(t_game *game)
{
	print_minimap_background(game);
	print_minimap_walls(game);
	print_minimap_player(game);
	print_player_view(game);
}

	// //create vertical lines
	// x = MINIMAP_POSITIONX;
	//   while (x <= MINIMAP_POSITIONX + MINIMAP_WIDTH)
    // {
    //     int y = MINIMAP_POSITIONY;
    //     while (y <= MINIMAP_POSITIONY + MINIMAP_HEIGHT)
    //     {
    //         put_pixel_canva(&game->scene, x, y, get_trgb(0, 0, 101, 0));
    //         y++;
    //     }
    //     x += MINIMAP_SCALE;
    // }
	// //create horizontal lines
	// y = MINIMAP_POSITIONY;
    // while (y <= MINIMAP_POSITIONY + MINIMAP_HEIGHT)
    // {
    //     x = MINIMAP_POSITIONX;
    //     while (x <= MINIMAP_POSITIONX + MINIMAP_WIDTH)
    //     {
    //         put_pixel_canva(&game->scene, x, y, get_trgb(0, 0, 101, 0));
    //         x++;
    //     }
    //     y += MINIMAP_SCALE;
    // }