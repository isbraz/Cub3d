/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/02/14 15:54:12 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.window);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	free_map(&game->map);
	return (exit(0), 0);
}

int ft_loop(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	printf("key pressed: %d\n", key);
	//implement...
	return (0);
}

void init_variables(t_player *player)
{
	player->pos_x = 22;
	player->pos_y = 12;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->dir_x = -1;
	player->dir_y = 0;
}


int main(int argc, char *argv[])
{
	t_game game;
	t_player player;

	if (argc != 2)
		exit_error(NULL, ARGUMENTS_ERROR);
	get_map(&game.map, argv);
	init_variables(&player);
	game.mlx.mlx = mlx_init();
	game.mlx.window = mlx_new_window(game.mlx.mlx, 200, 200, "cub3D!");
	mlx_hook(game.mlx.window, 17, (1L<<3), ft_close, &game);
	mlx_hook(game.mlx.window, 2, (1L<<0), ft_loop, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}

/*
	raycasting basic idea:
	use DDA algorithm
*/
