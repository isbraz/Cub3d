/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:34 by user              #+#    #+#             */
/*   Updated: 2024/02/27 16:08:02 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// void	perform_dda(t_game *game)
// {
// 	double	player_x;
// 	double	player_y;
// }

void	update_scene(t_game *game)
{
	int	y;
	int x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		if (y > WIN_HEIGHT / 2)
			while (x < WIN_WIDTH)
			{
				put_pixel_canva(&game->scene, x, y, get_trgb(0, 0, 85, 0));
				x++;
			}
		else
			while (x < WIN_WIDTH)
			{
				put_pixel_canva(&game->scene, x, y, get_trgb(0, 0, 160, 230));
				x++;
			}
		y++;
	}
	// //call dda and put wall
	// //to create the point of view, we need the player's position and the angle 
    // x = 0;
    // while (x < WIN_WIDTH)
	// {
    //     double ray_angle = game->player.direction - FOV_ANGLE / 2.0f + (float) x * (FOV_ANGLE / (double)WIN_WIDTH);
    //     double distance = cast_ray(game->map, game->player.position[X], game->player.position[Y], ray_angle);
	// 	// printf("distance: %f\n", distance);
    //     int wall_height = (int)(WIN_HEIGHT / distance);
    //     int wall_top = (WIN_HEIGHT - wall_height) / 2;
    //     int wall_bottom = wall_top + wall_height;
    //     int y = wall_top;
    //     while (y < wall_bottom)
	// 	{
    //         put_pixel_canva(&game->scene, x, y, get_trgb(0, 103, 2, 124)); // Cor da parede
    //         y++;
    //     }
    //     x++;
    // }
}
