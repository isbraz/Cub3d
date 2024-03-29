/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:31:20 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 21:17:11 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_images(t_game *game)
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

static void	init_angle(double *angle, char dir)
{
	*angle = (\
		(PI / 2) * (dir == 'S')) + \
		(PI * (dir == 'W')) + \
		(((3 * PI) / 2) * \
		(dir == 'N') \
	);
}

static void	init_delta(double delta[2], double angle)
{
	delta[X] = cos(angle);
	delta[Y] = sin(angle);
}

static void	init_plane(double plane[2], char dir)
{
	plane[X] = ((-0.5) * (dir == 'S')) + \
					((0.5) * (dir == 'N'));
	\
	plane[Y] = ((-0.5) * (dir == 'W')) + \
					((0.5) * (dir == 'E'));
}

void	new_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D!");
	game->map.minimap_pos[Y] = WIN_HEIGHT - MINIMAP_HEIGHT - MINIMAP_MARGIN;
	game->map.minimap_pos[X] = MINIMAP_MARGIN;
	game->show_map = 1;
	game->last = time_now();
	game->door_time = time_now();
	rotate_vector(game->map.spawn_pos, game->player.position, 0);
	init_angle(&game->player.angle, game->map.spawn_dir);
	init_plane(game->player.plane, game->map.spawn_dir);
	init_delta(game->player.delta, game->player.angle);
	init_images(game);
}
/*mlx_mouse_hide(game->mlx.mlx, game->mlx.window);*/