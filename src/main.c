/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/03/26 19:41:34 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

long	time_now(void)
{
	long int		now;
	struct timeval	time;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (now);
}

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

int	ft_mouse_listener(int x, int y, t_game *game)
{
	if (x == 400 || (time_now() - game->last) < 20 || game->pause)
		return (0);
	game->last = time_now();
	if (x < 400)
		move_vision(65361, game);
	if (x > 400)
		move_vision(65363, game);
	return (0);
}

int	ft_key_listener(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	if (key == 112)
		game->pause ^= 1;
	if (game->pause)
		return (0);
	if (key == 109)
		game->show_map ^= 1;
	if (key == 101)
	{
		game->padlock ^= 1;
		game->door_time = time_now();
	}
	move_vision(key, game);
	move_player(key, game);
	return (0);
}

int	ft_loop(t_game *game)
{
	if (!game->pause)
		mlx_mouse_move(game->mlx.mlx, game->mlx.window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	update_scene(game);
	if (game->show_map)
		update_minimap(game);
	update_door(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->scene.id, 0, 0);
	return (0);
}

void	set_image(t_game *game, t_image *image, char *path)
{
	image->id = mlx_xpm_file_to_image(
		game->mlx.mlx,
		path,
		&image->width,
		&image->height
	);
	if (!image->id)
	{
		printf("Error\nxpm error.\n");
		ft_close(game);
	}
	image->addr = mlx_get_data_addr(
		image->id,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian
	);
}

void	init_images(t_game *game)
{
	set_image(game, &game->textures[NO], game->map.types_info[NO]);
	set_image(game, &game->textures[SO], game->map.types_info[SO]);
	set_image(game, &game->textures[WE], game->map.types_info[WE]);
	set_image(game, &game->textures[EA], game->map.types_info[EA]);
	set_image(game, &game->door[0], "./src/textures/closed.xpm");
	set_image(game, &game->door[1], "./src/textures/closed1.xpm");
	set_image(game, &game->door[2], "./src/textures/closed2.xpm");
	set_image(game, &game->door[3], "./src/textures/closed3.xpm");
	set_image(game, &game->door[4], "./src/textures/open.xpm");
}

void	new_game(t_game *game)
{
	char	dir;

	dir = game->map.spawn_dir;
	game->show_map = 1;
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D!");
	new_canvas(&game->scene, game->mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	init_images(game);
	game->player.position[X] = game->map.spawn_pos[X] + 0.5;
	game->player.position[Y] = game->map.spawn_pos[Y] + 0.5;
	game->player.angle = ((PI / 2) * (dir == 'S')) + (PI * (dir == 'W')) + (((3 * PI) / 2) * (dir == 'N'));
	game->player.delta[X] = cos(game->player.angle);
	game->player.delta[Y] = sin(game->player.angle);
	game->player.plane[X] = ((-0.5) * (dir == 'S')) + ((0.5) * (dir == 'N'));
	game->player.plane[Y] = ((-0.5) * (dir == 'W')) + ((0.5) * (dir == 'E'));
	game->last = time_now();
	game->door_time = time_now();
	// mlx_mouse_hide(game->mlx.mlx, game->mlx.window);
}

int main(int argc, char *argv[])
{
	t_game game;
	t_player player;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		exit_error(NULL, ARGUMENTS_ERROR);
	get_map(&game.map, argv);
	new_game(&game);
	mlx_hook(game.mlx.window, 17, (1L<<3), ft_close, &game);
	mlx_hook(game.mlx.window, 2, (1L<<0), ft_key_listener, &game);
	mlx_hook(game.mlx.window, 6, (1L<<6), ft_mouse_listener, &game);
	mlx_loop_hook(game.mlx.mlx, ft_loop, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
