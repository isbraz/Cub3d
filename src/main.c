/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/03/07 15:49:35 by isbraz-d         ###   ########.fr       */
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

void	move_vision(int key, t_game *game)
{
	if (key == 65361)
	{
		if (game->player.pa < 0)
			game->player.pa += 2 * PI;
		game->player.pa -= 0.1;
		game->player.pdx = cos(game->player.pa);
		game->player.pdy = sin(game->player.pa);
	}
	if (key == 65363)
	{
		if (game->player.pa > (2 * PI))
			game->player.pa -= 2 * PI;
		game->player.pa += 0.1;
		game->player.pdx = cos(game->player.pa);
		game->player.pdy = sin(game->player.pa);
	}
}

//arrows up = 65362
//arrows down = 65364
//arrows left = 65361
//arrows right = 65363

void	move_player(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.position[X];
	y = game->player.position[Y];
	if (key == 119)
	{
		// if (y && game->map.map[y - 1][x] != '1')
		// {
		game->player.position[X] += (game->player.pdx / 2);
		game->player.position[Y] += (game->player.pdy / 2);
		// }
	}
	// if (key == 115)
	// {
	// 	if (game->map.map[y + 1][x] != '1')
	// 		game->player.position[Y] += 0.1;
	// }
	// if (key == 97)
	// {
	// 	if (x && game->map.map[y][x - 1] != '1')
	// 		game->player.position[X] -= 0.1;
	// }
	// if (key == 100)
	// {
	// 	if (game->map.map[y][x + 1] != '1')
	// 		game->player.position[X] += 0.1;
	// }
}

int	ft_key_listener(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	move_vision(key, game);
	move_player(key, game);
	// printf("key pressed: %d\n", key);
	return (0);
}

int	ft_loop(t_game *game)
{
	update_scene(game);
	update_minimap(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->scene.id, 0, 0);
	return (0);
}

void	new_game(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D!");
	new_canvas(&game->scene, game->mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	game->player.position[X] = game->map.spawn_pos[X];
	game->player.position[Y] = game->map.spawn_pos[Y];
	game->player.pa = 2;
	game->player.pdx = cos(game->player.pa);
	game->player.pdy = sin(game->player.pa);
}

int main(int argc, char *argv[])
{
	t_game game;
	t_player player;

	if (argc != 2)
		exit_error(NULL, ARGUMENTS_ERROR);
	get_map(&game.map, argv);
	new_game(&game);
	mlx_hook(game.mlx.window, 17, (1L<<3), ft_close, &game);
	mlx_hook(game.mlx.window, 2, (1L<<0), ft_key_listener, &game);
	mlx_loop_hook(game.mlx.mlx, ft_loop, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}

/*
	utils math function:
	sqrt();

	soma de vetores:
	v1x + v2x
	v1y + v2y
*/
