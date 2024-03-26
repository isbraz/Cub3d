/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:55 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/26 21:12:15 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	create_walls(t_game game, int x);

static void	init_calc(t_game *game, double c_x)
{
	game->raycast.raydiry = game->player.delta[Y] + game->player.plane[Y] * c_x;
	game->raycast.raydirx = game->player.delta[X] + game->player.plane[X] * c_x;
	game->raycast.mapx = (int)game->player.position[X];
	game->raycast.mapy = (int)game->player.position[Y];
	game->raycast.deltadistx = fabs(1 / game->raycast.raydirx);
	game->raycast.deltadisty = fabs(1 / game->raycast.raydiry);
}

static void	do_steps(t_game *game)
{
	if (game->raycast.raydirx < 0)
	{
		game->raycast.stepx = -1;
		game->raycast.sidedistx = (game->player.position[X] - 
				game->raycast.mapx) * game->raycast.deltadistx;
	}
	else
	{
		game->raycast.stepx = 1;
		game->raycast.sidedistx = (game->raycast.mapx + 1.0 - 
				game->player.position[X]) * game->raycast.deltadistx;
	}
	if (game->raycast.raydiry < 0)
	{
		game->raycast.stepy = -1;
		game->raycast.sidedisty = (game->player.position[Y] - 
				game->raycast.mapy) * game->raycast.deltadisty;
	}
	else
	{
		game->raycast.stepy = 1;
		game->raycast.sidedisty = (game->raycast.mapy + 1.0 - 
				game->player.position[Y]) * game->raycast.deltadisty;
	}
}

static void	draw_wall_line(t_game *game, int draw_start, int draw_end, int tex_x, int x)
{
	int	d;
	int	tex_y;
	int	color;

	while (draw_start < draw_end)
	{
		d = draw_start * 256 - WIN_HEIGHT * 128 + game->raycast.lineheight * 128;
		tex_y = ((d * game->textures->height) / game->raycast.lineheight) / 256;
		if (tex_y <= -1 || tex_x <= -1)
			return ;
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '1')
			color = get_pixel_canva(&game->textures[game->raycast.c], tex_x, tex_y);
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '2')
		{
			tex_y = ((d * game->door[game->d].height) / game->raycast.lineheight) / 256;
			color = get_pixel_canva(&game->door[game->d], tex_x * 0.15, tex_y);
		}
		put_pixel_canva(&game->scene, x, draw_start, color);
		draw_start++;
	}
}

static void	set_texture(t_game *game)
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

static double	get_distance(t_game *game)
{
	double	perp_wall_dist;

	if (game->raycast.side == 0)
		perp_wall_dist = (game->raycast.sidedistx - game->raycast.deltadistx);
	else
		perp_wall_dist = (game->raycast.sidedisty - game->raycast.deltadisty);
	return (perp_wall_dist);
}

static double	perform_dda(t_game *game, int x)
{
	game->raycast.hit = 0;
	while (game->raycast.hit == 0)
	{
		if (game->raycast.sidedistx < game->raycast.sidedisty)
		{
			game->raycast.sidedistx += game->raycast.deltadistx;
			game->raycast.mapx += game->raycast.stepx;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.sidedisty += game->raycast.deltadisty;
			game->raycast.mapy += game->raycast.stepy;
			game->raycast.side = 1;
		}
		if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '1' \
		|| game->map.map[game->raycast.mapy][game->raycast.mapx] == '2')
		{
			if (game->map.map[game->raycast.mapy][game->raycast.mapx] == '2')
				create_walls(*game, x);
			game->raycast.hit = 1;
			set_texture(game);
			break;
		}
	}
	return (get_distance(game));
}


void	create_walls(t_game game, int x)
{
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;
	double	wall_x;
	int		tex_x;

	perp_wall_dist = perform_dda(&game, x);
	game.raycast.lineheight = (int)(WIN_HEIGHT / perp_wall_dist);
	draw_start = -game.raycast.lineheight / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = game.raycast.lineheight / 2 + WIN_HEIGHT / 2;
	if (draw_end > WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	if (game.raycast.side == 0)
		wall_x = game.player.position[Y] + perp_wall_dist * game.raycast.raydiry;
	else
		wall_x = game.player.position[X] + perp_wall_dist * game.raycast.raydirx;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(game.textures[game.raycast.c].width));
	if (game.raycast.side == 0 && game.raycast.raydirx > 0)
		tex_x = game.textures[0].width - tex_x - 1;
	if (game.raycast.side == 1 && game.raycast.raydiry < 0)
		tex_x = game.textures[0].width - tex_x - 1;
	draw_wall_line(&game, draw_start, draw_end, tex_x, x);
}

void	raycast(t_game *game)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_HEIGHT - 1;
		init_calc(game, camera_x);
		do_steps(game);
		create_walls(*game, x);
		x++;
	}
}
