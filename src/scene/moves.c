/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/17 14:21:52 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	int		dest_x;
	int		dest_y;
	int		start;
	double	new[2];

	start = 30;
	while (start >= -30)
	{
		rotate_vector(delta, new, start);
		dest_x = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + (int)(new[X] * 600);
		dest_y = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + (int)(new[Y] * 600);
		if (draw_view_line2(game, dest_x, dest_y, delta) <= 15)
			return (1);
		start--;
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
