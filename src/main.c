/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/03/26 20:25:56 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_images(t_game *game)
{
	new_canvas(&game->scene, game->mlx, WIN_HEIGHT, WIN_WIDTH);
	new_image(game, &game->textures[NO], game->map.types_info[NO]);
	new_image(game, &game->textures[SO], game->map.types_info[SO]);
	new_image(game, &game->textures[WE], game->map.types_info[WE]);
	new_image(game, &game->textures[EA], game->map.types_info[EA]);
	new_image(game, &game->door[0], "./src/textures/closed.xpm");
	new_image(game, &game->door[1], "./src/textures/closed1.xpm");
	new_image(game, &game->door[2], "./src/textures/closed2.xpm");
	new_image(game, &game->door[3], "./src/textures/closed3.xpm");
	new_image(game, &game->door[4], "./src/textures/open.xpm");
}

void	new_game(t_game *game)
{
	char	dir;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D!");
	init_images(game);
	game->show_map = 1;
	dir = game->map.spawn_dir;
	game->player.position[X] = game->map.spawn_pos[X] + 0.5;
	game->player.position[Y] = game->map.spawn_pos[Y] + 0.5;
	game->player.angle = ((PI / 2) * (dir == 'S')) + (PI * (dir == 'W')) + (((3 * PI) / 2) * (dir == 'N'));
	game->player.delta[X] = cos(game->player.angle);
	game->player.delta[Y] = sin(game->player.angle);
	game->player.plane[X] = ((-0.5) * (dir == 'S')) + ((0.5) * (dir == 'N'));
	game->player.plane[Y] = ((-0.5) * (dir == 'W')) + ((0.5) * (dir == 'E'));
	game->last = time_now();
	game->door_time = time_now();
}
/*mlx_mouse_hide(game->mlx.mlx, game->mlx.window);*/

int main(int argc, char *argv[])
{
	t_game game;
	t_player player;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		exit_parsing_error(NULL, ARGUMENTS_ERROR);
	get_map(&game.map, argv);
	new_game(&game);
	mlx_hook(game.window, 17, (1L<<3), ft_close, &game);
	mlx_hook(game.window, 2, (1L<<0), key_listener, &game);
	mlx_hook(game.window, 6, (1L<<6), mouse_listener, &game);
	mlx_loop_hook(game.mlx, ft_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
