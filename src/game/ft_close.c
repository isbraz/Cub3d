/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:59:25 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <stdlib.h>

int	ft_close(t_game *game)
{
	int	i;

	i = -1;
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->scene.id);
		while (++i < 4)
			if (game->wall[i].id)
				mlx_destroy_image(game->mlx, game->wall[i].id);
		i = -1;
		while (++i < 5)
			if (game->doors.door[i].id)
				mlx_destroy_image(game->mlx, game->doors.door[i].id);
	}
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(&game->map);
	return (exit(0), 0);
}
