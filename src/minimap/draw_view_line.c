/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:39:24 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/15 12:51:22 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void draw_view_line(t_game *game, int x1, int y1)
{
	int	err;
	int	e2;
	int	x0;
	int	y0;

	x0 = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + 2;
	y0 = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + 2;
	err = abs(x1 - x0) - abs(y1 - y0);
	while (x0 != x1 || y0 != y1)
	{
		if (get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 230, 230, 230) && \
				get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 255, 50, 50))
				break;
		put_pixel_canva(&game->scene, x0, y0, get_trgb(0, 255, 50, 50));
		e2 = 2 * err;
		if (e2 > -abs(y1 - y0))
		{
				err -= abs(y1 - y0);
				x0 += x0 < x1 ? 1 : -1;
		}
		if (e2 < abs(x1 - x0))
		{
				err += abs(x1 - x0);
				y0 += y0 < y1 ? 1 : -1;
		}
	}
}