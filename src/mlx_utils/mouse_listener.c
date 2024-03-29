/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:04:07 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:28:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

int	mouse_listener(int x, int y, t_game *game)
{
	if (x == 400 || (time_now() - game->last_mouse_move) < 20 || game->pause)
		return (0);
	game->last_mouse_move = time_now();
	if (x < 400)
		move_vision(65361, game);
	if (x > 400)
		move_vision(65363, game);
	return (0);
}
