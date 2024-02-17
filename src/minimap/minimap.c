/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:02:58 by user              #+#    #+#             */
/*   Updated: 2024/02/17 16:22:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define SIZE 10

static void	print_temp_obj(t_game *game, int y, int x, int color)
{
	int i = x;
	int j = y;

	while (j < (y + SIZE))
	{
		i = x;
		while (i < (x + SIZE))
			put_pixel_canva(&game->minimap, i++, j, color);
		j++;
	}
}

static void clear_canvas(t_image *canvas, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
			put_pixel_canva(canvas, x++, y, get_trgb(0, 0, 0, 0));
		y++;
	}
}

static void	print_minimap(t_game *game)
{
	int y;
	int x;
	y = 0;
	x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				print_temp_obj(game, ((y * SIZE) + (WIN_HEIGTH / 2) - (game->player.position[Y] * SIZE)),
				((x * SIZE) + (WIN_WIDTH / 2) - (game->player.position[X] * SIZE)), get_trgb(0, 255, 255, 255));
			if (game->map.map[y][x] == '0' ||
				game->map.map[y][x] == 'N' ||
				game->map.map[y][x] == 'E' ||
				game->map.map[y][x] == 'W' ||
				game->map.map[y][x] == 'S')
				print_temp_obj(game, ((y * SIZE) + (WIN_HEIGTH / 2) - (game->player.position[Y] * SIZE)),
				((x * SIZE) + (WIN_WIDTH / 2) - (game->player.position[X] * SIZE)), get_trgb(0, 121, 122, 122));
			x++;
		}
		y++;
	}
}

static void	print_miniplayer(t_game *game)
{
	// int	y = game->player.position[Y];
	// int x = game->player.position[X];
	print_temp_obj(game, WIN_HEIGTH / 2, WIN_WIDTH / 2, get_trgb(0, 255, 226, 3));
}

void	update_minimap(t_game *game)
{
	clear_canvas(&game->minimap, WIN_HEIGTH, WIN_WIDTH);
	print_minimap(game);
	print_miniplayer(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->minimap.id, 0, 0);
}
