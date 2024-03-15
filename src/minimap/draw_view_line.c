/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:39:24 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/15 13:25:14 by llopes-d         ###   ########.fr       */
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

static int	is_wall(t_game *game, int pixelx, int pixely)
{
	int	curr;

	curr = get_pixel_canva(&game->scene, pixelx, pixely);
	if (curr != get_trgb(0, 230, 230, 230) && curr != get_trgb(0, 255, 50, 50))
		return (1);
	return (0);
}

void	draw_view_line(t_game *game, int finalX, int finalY)
{
	int	err;
	int	temp;
	int	pixelx;
	int	pixely;

	pixelx = MINIMAP_POSITIONX + (MINIMAP_WIDTH / 2) + 2;
	pixely = MINIMAP_POSITIONY + (MINIMAP_HEIGHT / 2) + 2;
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
	}
}
