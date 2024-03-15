/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/03/15 18:18:45 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_close(t_game *game)
{
	if (game->mlx.mlx)
	{
		mlx_destroy_image(game->mlx.mlx, game->scene.id);
	}
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
	// printf("key = %d\n", key);
	move_vision(key, game);
	move_player(key, game);
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
	char	dir;

	dir = game->map.spawn_dir;
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D!");
	new_canvas(&game->scene, game->mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	game->wall_textures[0].id = mlx_xpm_file_to_image(game->mlx.mlx, \
		"src/textures/wall1.xpm", &game->wall_textures[0].width, \
		&game->wall_textures[0].height);
	game->wall_textures[0].addr = mlx_get_data_addr(game->wall_textures[0].id, &game->wall_textures[0].bits_per_pixel, &game->wall_textures[0].line_length, &game->wall_textures[0].endian);
	game->player.position[X] = game->map.spawn_pos[X];
	game->player.position[Y] = game->map.spawn_pos[Y];
	game->player.pa = ((PI / 2) * (dir == 'S')) + (PI * (dir == 'W')) + (((3 * PI) / 2) * (dir == 'N'));
	game->player.pdx = cos(game->player.pa);
	game->player.pdy = sin(game->player.pa);
	game->player.planeX = ((-0.5) * (dir == 'S')) + ((0.5) * (dir == 'N'));
	game->player.planeY = ((-0.5) * (dir == 'W')) + ((0.5) * (dir == 'E'));
}

int main(int argc, char *argv[])
{
	t_game game;
	t_player player;

	game.mlx.mlx = NULL;
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
	camera plane*
	FOV*
	
*/
