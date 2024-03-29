/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

int	main(int argc, char *argv[])
{
	t_game		game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		exit_parsing_error(NULL, ARGUMENTS_ERROR);
	get_map(&game.map, argv);
	new_game(&game);
	mlx_hook(game.window, 17, (1L << 3), ft_close, &game);
	mlx_hook(game.window, 2, (1L << 0), key_listener, &game);
	mlx_hook(game.window, 6, (1L << 6), mouse_listener, &game);
	mlx_loop_hook(game.mlx, ft_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
