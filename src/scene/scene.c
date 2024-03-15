/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:34 by user              #+#    #+#             */
/*   Updated: 2024/03/14 17:10:25 by isbraz-d         ###   ########.fr       */
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
				put_pixel_canva(&game->scene, x, y, get_trgb(0, 75, 75, 75));
				x++;
			}
		else
			while (x < WIN_WIDTH)
			{
				put_pixel_canva(&game->scene, x, y, get_trgb(0, 50, 50, 50));
				x++;
			}
		y++;
	}
	raycast(game);
}

