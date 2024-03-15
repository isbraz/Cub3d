/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/15 18:26:41 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_vision(int key, t_game *game)
{
	double	oldplaneX;
	double	oldplaneY;

	if (key == 65361)
	{
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		game->player.angle -= 0.1;
		game->player.delta[X] = cos(game->player.angle);
		game->player.delta[Y] = sin(game->player.angle);
		oldplaneX = game->player.plane[X];
		game->player.plane[X] = game->player.plane[X] * cos(-0.1) - game->player.plane[Y] * sin(-0.1);
		game->player.plane[Y] = oldplaneX * sin(-0.1) + game->player.plane[Y] * cos(-0.1);
	}
	if (key == 65363)
	{
		if (game->player.angle > (2 * PI))
			game->player.angle -= 2 * PI;
		game->player.angle += 0.1;
		game->player.delta[X] = cos(game->player.angle);
		game->player.delta[Y] = sin(game->player.angle);
		oldplaneX = game->player.plane[X];
		game->player.plane[X] = game->player.plane[X] * cos(0.1) - game->player.plane[Y] * sin(0.1);
		game->player.plane[Y] = oldplaneX * sin(0.1) + game->player.plane[Y] * cos(0.1);
	}
}

void	move_player(int key, t_game *game)
{
	if (key == 119 && game->map.map[(int)(game->player.position[Y] + game->player.delta[Y] * SPEED)][(int)(game->player.position[X] + game->player.delta[X] * SPEED)] != '1')
	{
		game->player.position[X] += (game->player.delta[X] * SPEED);
		game->player.position[Y] += (game->player.delta[Y] * SPEED);
	}
	if (key == 115 && game->map.map[(int)(game->player.position[Y] - game->player.delta[Y] * SPEED)][(int)(game->player.position[X] - game->player.delta[X] * SPEED)] != '1')
	{
		game->player.position[X] -= (game->player.delta[X] * SPEED);
		game->player.position[Y] -= (game->player.delta[Y] * SPEED);
	}
	if (key == 97 && game->map.map[(int)(game->player.position[Y] - game->player.delta[X] * SPEED)][(int)(game->player.position[X] + game->player.delta[Y] * SPEED)] != '1')
	{
		game->player.position[X] += (game->player.delta[Y] * SPEED);
		game->player.position[Y] += (-game->player.delta[X] * SPEED);
	}
	if (key == 100 && game->map.map[(int)(game->player.position[Y] + game->player.delta[X] * SPEED)][(int)(game->player.position[X] - game->player.delta[Y] * SPEED)] != '1')
	{
		game->player.position[X] += (-game->player.delta[Y] * SPEED);
		game->player.position[Y] += (game->player.delta[X] * SPEED);
	}
}
