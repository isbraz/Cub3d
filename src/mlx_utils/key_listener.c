/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:36 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 20:05:49 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_listener(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	if (key == 112)
		game->pause ^= 1;
	if (game->pause)
		return (0);
	if (key == 109)
		game->show_map ^= 1;
	if (key == 101)
	{
		game->padlock ^= 1;
		game->door_time = time_now();
	}
	move_vision(key, game);
	move_player(key, game);
	return (0);
}
