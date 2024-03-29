/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:36 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

int	key_listener(int key, t_game *game)
{
	t_doors	*doors;

	doors = &game->doors;
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
		doors->lock ^= 1;
		doors->time = time_now();
	}
	move_vision(key, game);
	move_player(key, game);
	return (0);
}
