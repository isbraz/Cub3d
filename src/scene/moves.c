/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:16 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/17 14:19:47 by llopes-d         ###   ########.fr       */
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
static void	update_pixel(int *pixel, int next)
{
	if (*pixel < next)
		*pixel += 1;
	else
		*pixel += -1;
}

static int	is_wall(t_game *game, int pixelx, int pixely)
{
	int	curr;

	curr = get_pixel_canva(&game->scene, pixelx, pixely);
	if (curr != get_trgb(0, 230, 230, 230) && curr != get_trgb(0, 255, 50, 50))
		return (1);
	return (0);
}

static int	draw_view_line2(t_game *game, int finalX, int finalY, double delta[2])
{
	int	err;
	int	temp;
	int	pixelx;
	int	pixely;
	int distance = 0;
	pixelx = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + 2 + delta[X];
	pixely = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + 2 + delta[Y];
	err = abs(finalX - pixelx) - abs(finalY - pixely);
	while (pixelx != finalX || pixely != finalY)
	{
		if (is_wall(game, pixelx, pixely))
			break ;
		put_pixel_canva(&game->scene, pixelx, pixely, get_trgb(0, 255, 50, 50));
		temp = 2 * err;
		if (temp > -abs(finalY - pixely))
		{
			err -= abs(finalY - pixely);
			update_pixel(&pixelx, finalX);
		}
		if (temp < abs(finalX - pixelx))
		{
			err += abs(finalX - pixelx);
			update_pixel(&pixely, finalY);
		}
		distance++;
	}
	return distance;
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
<<<<<<< HEAD
	if (key == 119 && game->map.map[(int)(game->player.position[Y] + game->player.delta[Y] * SPEED)][(int)(game->player.position[X] + game->player.delta[X] * SPEED)] != '1')
		rotate_vector(game->player.delta, new, 0);
	if (key == 115 && game->map.map[(int)(game->player.position[Y] - game->player.delta[Y] * SPEED)][(int)(game->player.position[X] - game->player.delta[X] * SPEED)] != '1')
		rotate_vector(game->player.delta, new, 180);
	if (key == 97 && game->map.map[(int)(game->player.position[Y] - game->player.delta[X] * SPEED)][(int)(game->player.position[X] + game->player.delta[Y] * SPEED)] != '1')
		rotate_vector(game->player.delta, new, 270);
	if (key == 100 && game->map.map[(int)(game->player.position[Y] + game->player.delta[X] * SPEED)][(int)(game->player.position[X] - game->player.delta[Y] * SPEED)] != '1')
		rotate_vector(game->player.delta, new, 90);
	if (has_collison(game, new))
		return;
=======
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
>>>>>>> 8c15a11 (add collison)
	game->player.position[X] += (new[X] * SPEED);
	game->player.position[Y] += (new[Y] * SPEED);
}
