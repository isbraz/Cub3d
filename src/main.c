/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/02/16 18:20:50 by user             ###   ########.fr       */
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

int	ft_key_listener(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	if (key == 119)
		game->player.position[Y] -= 1;
	if (key == 115)
		game->player.position[Y] += 1;
	if (key == 97)
		game->player.position[X] -= 1;
	if (key == 100)
		game->player.position[X] += 1;
	printf("key pressed: %d\n", key);
	return (0);
}

int	ft_loop(t_game *game)
{
	update_minimap(game);
	return (0);
}

void	new_game(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGTH, "cub3D!");
	new_canvas(&game->minimap, game->mlx.mlx);
	game->player.position[X] = game->map.spawn_pos[X];
	game->player.position[Y] = game->map.spawn_pos[Y];
}

int main(int argc, char *argv[])
{
	t_game game;

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
