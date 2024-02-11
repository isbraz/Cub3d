/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/02/11 16:38:35 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		exit_error(NULL, ARGUMENTS_ERROR);
	get_map(&map, argv);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 200, 200, "cub3D!");
	mlx_loop(mlx.mlx);
	printf("successs\n");
	return (0);
}
