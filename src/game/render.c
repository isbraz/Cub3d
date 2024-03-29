/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:55:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/29 13:32:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	get_raycast_door_config(t_game *game, int d, int *color)
{
	t_image		door;
	t_raycast	*raycast;

	raycast = &game->raycast;
	door = game->doors.door[game->doors.index];
	raycast->tex_y = ((d * door.height) / raycast->lineheight) / 256;
	*color = get_pixel(&door, raycast->tex_x * 0.15, raycast->tex_y);
}

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
			color = get_pixel(&game->textures[game->raycast.c], \
			game->raycast.tex_x, game->raycast.tex_y);
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '2')
			get_raycast_door_config(game, d, &color);
		put_pixel(&game->scene, x, draw_start, color);
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
