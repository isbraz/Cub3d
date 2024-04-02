/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:42 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_calc(t_game *game, double c_x)
{
	game->raycast.raydiry = game->player.delta[Y] + game->player.plane[Y] * c_x;
	game->raycast.raydirx = game->player.delta[X] + game->player.plane[X] * c_x;
	game->raycast.mapx = (int)game->player.position[X];
	game->raycast.mapy = (int)game->player.position[Y];
	game->raycast.deltadistx = fabs(1 / game->raycast.raydirx);
	game->raycast.deltadisty = fabs(1 / game->raycast.raydiry);
}

void	do_steps(t_game *game)
{
	if (game->raycast.raydirx < 0)
	{
		game->raycast.stepx = -1;
		game->raycast.sidedistx = (game->player.position[X] - \
				game->raycast.mapx) * game->raycast.deltadistx;
	}
	else
	{
		game->raycast.stepx = 1;
		game->raycast.sidedistx = (game->raycast.mapx + 1.0 - \
				game->player.position[X]) * game->raycast.deltadistx;
	}
	if (game->raycast.raydiry < 0)
	{
		game->raycast.stepy = -1;
		game->raycast.sidedisty = (game->player.position[Y] - \
				game->raycast.mapy) * game->raycast.deltadisty;
	}
	else
	{
		game->raycast.stepy = 1;
		game->raycast.sidedisty = (game->raycast.mapy + 1.0 - \
				game->player.position[Y]) * game->raycast.deltadisty;
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

double	perform_dda(t_game *game, int x)
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
		}
	}
	return (get_distance(game));
}
