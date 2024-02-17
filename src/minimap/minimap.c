/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/02/17 17:33:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define SIZE 9

static void	print_temp_obj(t_game *game, int y, int x, int color)
{
	int i = x;
	int j = y;

	while (j < (y + SIZE) && j > 0 && j < MINIMAP_HEIGHT - 5)
	{
		i = x;
		while (i < (x + SIZE) && i > 0 && i < MINIMAP_WIDTH - 5)
			put_pixel_canva(&game->minimap, i++, j, color);
		j++;
	}
}

static void	print_minimap(t_game *game)
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
			if (game->map.map[y][x] == '1')
				print_temp_obj(game, ((y * SIZE) + (MINIMAP_HEIGHT / 2) - (game->player.position[Y] * SIZE)),
				((x * SIZE) + (MINIMAP_WIDTH / 2) - (game->player.position[X] * SIZE)), get_trgb(0, 255, 255, 255));
			if (game->map.map[y][x] == '0' ||
				game->map.map[y][x] == 'N' ||
				game->map.map[y][x] == 'E' ||
				game->map.map[y][x] == 'W' ||
				game->map.map[y][x] == 'S')
				print_temp_obj(game, ((y * SIZE) + (MINIMAP_HEIGHT / 2) - (game->player.position[Y] * SIZE)),
				((x * SIZE) + (MINIMAP_WIDTH / 2) - (game->player.position[X] * SIZE)), get_trgb(0, 121, 122, 122));
			x++;
		}
		y++;
	}
}

static void	print_miniplayer(t_game *game)
{
	// int	y = game->player.position[Y];
	// int x = game->player.position[X];
	print_temp_obj(game, MINIMAP_HEIGHT / 2, MINIMAP_WIDTH / 2, get_trgb(0, 255, 226, 3));
}

void print_border(t_game *game, int height, int width)
{
	int i = 0;
	int color =  get_trgb(0, 0, 0, 255);
	while (i < width)
		put_pixel_canva(&game->minimap, i++, 0,color);
	i = 0;
	while (i < width)
		put_pixel_canva(&game->minimap, i++, height,color);
	i = 0;
	while (i < height)
		put_pixel_canva(&game->minimap, 0, i++,color);
	i = 0;
	while (i < height)
		put_pixel_canva(&game->minimap, width, i++,color);
}

void	update_minimap(t_game *game)
{
	clear_canvas(&game->minimap, WIN_HEIGHT, WIN_WIDTH);
	print_border(game, MINIMAP_HEIGHT, MINIMAP_WIDTH);
	print_minimap(game);
	print_miniplayer(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->minimap.id, 20, WIN_HEIGHT - MINIMAP_HEIGHT - 20);
}
