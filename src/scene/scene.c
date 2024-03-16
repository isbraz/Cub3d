/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:34 by user              #+#    #+#             */
/*   Updated: 2024/03/16 18:22:40 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_scene(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		if (y > WIN_HEIGHT / 2)
			while (x < WIN_WIDTH)
				put_pixel_canva(&game->scene, x++, y, get_trgb(0, 75, 75, 75));
		else
			while (x < WIN_WIDTH)
				put_pixel_canva(&game->scene, x++, y, get_trgb(0, 50, 50, 50));
		y++;
	}
	raycast(game);
}
