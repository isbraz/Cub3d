/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:28:24 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/26 15:22:51 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	close_door(t_game *game)
{
	if (time_now() - game->door_time > 100)
		game->d = 3;
	if (time_now() - game->door_time > 300)
		game->d = 2;
	if (time_now() - game->door_time > 500)
		game->d = 1;
	if (time_now() - game->door_time > 700)
		game->d = 0;
}

void	update_door(t_game *game)
{
	if (!game->padlock && game->d != 0)
	{
		close_door(game);
		return ;
	}
	if (!game->padlock)
		return ;
	if (time_now() - game->door_time > 100)
		game->d = 1;
	if (time_now() - game->door_time > 300)
		game->d = 2;
	if (time_now() - game->door_time > 500)
		game->d = 3;
	if (time_now() - game->door_time > 700)
		game->d = 4;
}
