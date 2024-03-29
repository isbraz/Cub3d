/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:06:10 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <minimap.h>

int	ft_loop(t_game *game)
{
	int	width_pos;
	int	height_pos;

	width_pos = WIN_WIDTH / 2;
	height_pos = WIN_HEIGHT / 2;
	if (game->pause)
		return (0);
	mlx_put_image_to_window(game->mlx, game->window, game->scene.id, 0, 0);
	mlx_mouse_move(game->mlx, game->window, width_pos, height_pos);
	update_scene(game);
	update_door(game);
	update_minimap(game);
	return (0);
}
