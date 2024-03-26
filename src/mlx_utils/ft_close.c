/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:59:25 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 19:59:29 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_close(t_game *game)
{
	int i;

	i = -1;
	if (game->mlx.mlx)
	{
		mlx_destroy_image(game->mlx.mlx, game->scene.id);
		while (++i < 4)
			if (game->textures[i].id)
				mlx_destroy_image(game->mlx.mlx, game->textures[i].id);
		i = -1;
		while (++i < 5)
			if (game->door[i].id)
				mlx_destroy_image(game->mlx.mlx, game->door[i].id);
	}
	mlx_destroy_window(game->mlx.mlx, game->mlx.window);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	free_map(&game->map);
	return (exit(0), 0);
}
