/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/29 13:59:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

static void	rotate_vector(double vec[2], double dest[2], double degree)
{
	dest[X] = vec[X] * cos(degree * PI / 180) - vec[Y] * sin(degree * PI / 180);
	dest[Y] = vec[X] * sin(degree * PI / 180) + vec[Y] * cos(degree * PI / 180);
}

void	move_vision(int key, t_game *game)
{
	double	old[2];
	double	speed;

	speed = A_SPEED;
	if (key != 65361 && key != 65363)
		return ;
	if (key == 65361)
		speed = -A_SPEED;
	old[X] = game->player.plane[X];
	old[Y] = game->player.plane[Y];
	game->player.angle += speed;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	if (game->player.angle > (2 * PI))
		game->player.angle -= 2 * PI;
	game->player.delta[X] = cos(game->player.angle);
	game->player.delta[Y] = sin(game->player.angle);
	rotate_vector(old, game->player.plane, get_degree(speed));
}

static int	has_collison(t_game *game, double delta[2])
{
	double	new_pos[2];
	double	new_delta[2];
	int		start;

	start = 42;
	while (start >= -42)
	{
		rotate_vector(delta, new_delta, start);
		new_pos[X] = game->player.position[X] + new_delta[X] * 0.5;
		new_pos[Y] = game->player.position[Y] + new_delta[Y] * 0.5;
		if (game->map.map[(int)new_pos[Y]][(int)new_pos[X]] == '1' || \
			(game->map.map[(int)new_pos[Y]][(int)new_pos[X]] == '2' && \
			!game->doors.lock))
			return (1);
		start -= 10;
	}
	return (0);
}

void	move_player(int key, t_game *game)
{
	double	new[2];

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
