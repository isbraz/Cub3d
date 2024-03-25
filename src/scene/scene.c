/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:34 by user              #+#    #+#             */
/*   Updated: 2024/03/22 15:12:41 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_scene(t_game *game, char **floor_c, char **ceiling_c)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		if (y > WIN_HEIGHT / 2)
			while (x < WIN_WIDTH)
				put_pixel_canva(&game->scene, x++, y, get_trgb(0,  \
				ft_atoi(floor_c[0]), ft_atoi(floor_c[1]), ft_atoi(floor_c[2]))); //floor
		else
			while (x < WIN_WIDTH)
				put_pixel_canva(&game->scene, x++, y, get_trgb(0, \
				ft_atoi(ceiling_c[0]), ft_atoi(ceiling_c[1]), ft_atoi(ceiling_c[2]))); //ceiling
		y++;
	}
	raycast(game);
}
