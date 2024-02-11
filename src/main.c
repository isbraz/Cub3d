/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:09:45 by user              #+#    #+#             */
/*   Updated: 2024/02/11 18:01:08 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int ft_loop(int key, void *param)
{
	(void)param;
	if (key == 65307)
		exit(0);
	printf("key pressed: %d\n", key);
	return (0);
}

int main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		exit_error(NULL, ARGUMENTS_ERROR);
	get_map(&map, argv);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 200, 200, "cub3D!");
	mlx_hook(mlx.window, 17, (1L<<3), ft_close, NULL);
	mlx_hook(mlx.window, 2, (1L<<0), ft_loop, NULL);
	mlx_loop(mlx.mlx);
	printf("successs\n");
	free_map(&map);
	return (0);
}
