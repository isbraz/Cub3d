/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/11 10:43:45 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_vision(int key, t_game *game)
{
	if (key == 65361)
	{
		if (game->player.pa < 0)
			game->player.pa += 2 * PI;
		game->player.pa -= 0.1;
		game->player.pdx = cos(game->player.pa);
		game->player.pdy = sin(game->player.pa);
	}
	if (key == 65363)
	{
		if (game->player.pa > (2 * PI))
			game->player.pa -= 2 * PI;
		game->player.pa += 0.1;
		game->player.pdx = cos(game->player.pa);
		game->player.pdy = sin(game->player.pa);
	}
}

void	move_player(int key, t_game *game)
{
	if (key == 119)
	{
		game->player.position[X] += (game->player.pdx * SPEED);
		game->player.position[Y] += (game->player.pdy * SPEED);
	}
	if (key == 115)
	{
		game->player.position[X] -= (game->player.pdx * SPEED);
		game->player.position[Y] -= (game->player.pdy * SPEED);
	}
	if (key == 97)
	{
		game->player.position[X] += (game->player.pdy * SPEED);
		game->player.position[Y] += (-game->player.pdx * SPEED);
	}
	if (key == 100)
	{
		game->player.position[X] += (-game->player.pdy * SPEED);
		game->player.position[Y] += (game->player.pdx * SPEED);
	}
}
