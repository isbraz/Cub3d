/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:28:24 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

static void	close_door(t_game *game)
{
	if (time_now() - game->doors.time > 100)
		game->doors.index = 3;
	if (time_now() - game->doors.time > 300)
		game->doors.index = 2;
	if (time_now() - game->doors.time > 500)
		game->doors.index = 1;
	if (time_now() - game->doors.time > 700)
		game->doors.index = 0;
}

void	update_door(t_game *game)
{
	int	index;

	index = 0;
	if (!game->doors.lock && game->doors.index != 0)
	{
		close_door(game);
		return ;
	}
	if (!game->doors.lock)
		return ;
	if (time_now() - game->doors.time > 100)
		game->doors.index = 1;
	if (time_now() - game->doors.time > 300)
		game->doors.index = 2;
	if (time_now() - game->doors.time > 500)
		game->doors.index = 3;
	if (time_now() - game->doors.time > 700)
		game->doors.index = 4;
}
