/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:39:24 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 21:18:00 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	update_pixel(int *pixel, int next)
{
	if (*pixel < next)
		*pixel += 1;
	else
		*pixel += -1;
}

static int	is_wall(t_game *game, int pixel[2])
{
	int	curr;

	curr = get_pixel_canva(&game->scene, pixel[X], pixel[Y]);
	if (curr != get_trgb(0, 230, 230, 230) && curr != RAY_COLOR)
		return (1);
	return (0);
}

void	draw_view_line(t_game *game, int finalX, int finalY)
{
	int	err;
	int	temp;
	int	pixel[2];

	pixel[X] = game->map.minimap_pos[X] + (MINIMAP_WIDTH / 2) + 2;
	pixel[Y] = game->map.minimap_pos[Y] + (MINIMAP_HEIGHT / 2) + 2;
	err = abs(finalX - pixel[X]) - abs(finalY - pixel[Y]);
	while (pixel[X] != finalX || pixel[Y] != finalY)
	{
		if (is_wall(game, pixel))
			break ;
		put_pixel_canva(&game->scene, pixel[X], pixel[Y], RAY_COLOR);
		temp = 2 * err;
		if (temp > -abs(finalY - pixel[Y]))
		{
			err -= abs(finalY - pixel[Y]);
			update_pixel(&pixel[X], finalX);
		}
		if (temp < abs(finalX - pixel[X]))
		{
			err += abs(finalX - pixel[X]);
			update_pixel(&pixel[Y], finalY);
		}
	}
}
