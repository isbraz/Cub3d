/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/16 15:25:37 by llopes-d         ###   ########.fr       */
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


static int has_collison(t_game *game, double delta[2])
{
	double new_pos[2];
	double new_delta[2];
	int start = 42;

	while (start >= -42)
	{
		rotate_vector(delta, new_delta, start);
		new_pos[X] = game->player.position[X] + new_delta[X] * 0.5;
		new_pos[Y] = game->player.position[Y] + new_delta[Y] * 0.5;
		if (game->map.map[(int)new_pos[Y]][(int)new_pos[X]] == '1')
			return (1);
		start -= 10;
	}
	return (0);
}

void	move_player(int key, t_game *game)
{
	double new[2];
	if (key != 119 && key != 115 && key != 97 && key != 100)
		return ;
	if (key == 119)
		rotate_vector(game->player.delta, new, 0);
	if (key == 115)
		rotate_vector(game->player.delta, new, 180);
	if (key == 97)
		rotate_vector(game->player.delta, new, 270);
	if (key == 100)
		rotate_vector(game->player.delta, new, 90);
	if (has_collison(game, new))
		return ;
	game->player.position[X] += (new[X] * SPEED);
	game->player.position[Y] += (new[Y] * SPEED);
}
