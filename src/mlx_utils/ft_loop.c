/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:06:10 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 20:10:16 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_loop(t_game *game)
{
	int	width_pos;
	int	height_pos;

	width_pos = WIN_WIDTH / 2;
	height_pos = WIN_HEIGHT / 2;
	if (!game->pause)
		mlx_mouse_move(game->mlx.mlx, game->mlx.window, width_pos, height_pos);
	update_scene(game);
	update_minimap(game);
	update_door(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->scene.id, 0, 0);
	return (0);
}
