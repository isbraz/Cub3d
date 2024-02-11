/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:41:59 by user              #+#    #+#             */
/*   Updated: 2024/02/11 16:39:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_error(t_map *map, int status)
{
	free_map(map);
	if (status == ARGUMENTS_ERROR)
		write(2, "Error\nwrong arguments\n", 23);
	else if (status == OPENING_ERROR)
		write(2, "Error\nnot possible to open the map\n", 36);
	else if (status == BREAKS_ERROR)
		write(2, "Error\nempty line in the map\n", 29);
	else if (status == SPAWN_ERROR)
		write(2, "Error\ninvalid player position\n", 31);
	else if (status == TYPES_ERROR)
		write(2, "Error\ninvalid types info\n", 26);
	else if (status == WALL_ERROR)
		write(2, "Error\ninvalid wall closing\n", 28);
	exit(status);
}
