/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:55:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/28 13:07:12 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_wall_line(t_game *game, int draw_start, int draw_end, int x)
{
	int	d;
	int	color;

	while (draw_start < draw_end)
	{
		d = draw_start * 256 - WIN_HEIGHT * 128 + \
		game->raycast.lineheight * 128;
		game->raycast.tex_y = ((d * game->textures->height) / \
		game->raycast.lineheight) / 256;
		if (game->raycast.tex_y <= -1 || game->raycast.tex_x <= -1)
			return ;
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '1')
			color = get_pixel_canva(&game->textures[game->raycast.c], \
			game->raycast.tex_x, game->raycast.tex_y);
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '2')
		{
			game->raycast.tex_y = ((d * game->door[game->d].height) / \
			game->raycast.lineheight) / 256;
			color = get_pixel_canva(&game->door[game->d], \
			game->raycast.tex_x * 0.15, game->raycast.tex_y);
		}
		put_pixel_canva(&game->scene, x, draw_start, color);
		draw_start++;
	}
}

void	set_texture(t_game *game)
{
	if (game->raycast.side == 0)
	{
		if (game->raycast.raydirx > 0)
			game->raycast.c = WE;
		else
			game->raycast.c = EA;
	}
	else
	{
		if (game->raycast.raydiry > 0)
			game->raycast.c = NO;
		else
			game->raycast.c = SO;
	}
}

void	create_walls(t_game game, int x)
{
	int		draw_start;
	int		draw_end;
	double	distance;
	double	wall_x;

	distance = perform_dda(&game, x);
	game.raycast.lineheight = (int)(WIN_HEIGHT / distance);
	draw_start = -game.raycast.lineheight / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = game.raycast.lineheight / 2 + WIN_HEIGHT / 2;
	if (draw_end > WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	if (game.raycast.side == 0)
		wall_x = game.player.position[Y] + distance * game.raycast.raydiry;
	else
		wall_x = game.player.position[X] + distance * game.raycast.raydirx;
	wall_x -= floor((wall_x));
	game.raycast.tex_x = (int)(wall_x * \
	(double)(game.textures[game.raycast.c].width));
	if (game.raycast.side == 0 && game.raycast.raydirx > 0)
		game.raycast.tex_x = game.textures[0].width - game.raycast.tex_x - 1;
	if (game.raycast.side == 1 && game.raycast.raydiry < 0)
		game.raycast.tex_x = game.textures[0].width - game.raycast.tex_x - 1;
	draw_wall_line(&game, draw_start, draw_end, x);
}