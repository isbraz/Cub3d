/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:34 by user              #+#    #+#             */
/*   Updated: 2024/02/26 23:33:51 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	//call dda and put wall
	double player_x = game->player.position[X];
    double player_y = game->player.position[Y];
    double player_angle = 90.0;
    
    x = 0; // Reinicia x para começar do início da tela
    while (x < WIN_WIDTH) {
        double ray_angle = player_angle - FOV_ANGLE / 2 + x * (FOV_ANGLE / WIN_WIDTH);
        double distance = cast_ray(game->map, player_x, player_y, ray_angle);
        int wall_height = (int)(WIN_HEIGHT / distance);

        int wall_top = (WIN_HEIGHT - wall_height) / 2;
        int wall_bottom = wall_top + wall_height;
        int y = wall_top;
        while (y < wall_bottom) {
            put_pixel_canva(&game->scene, x, y, get_trgb(0, 103, 2, 124)); // Cor da parede
            y++;
        }
        x++;
    }
}


