/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:08:59 by user              #+#    #+#             */
/*   Updated: 2024/02/11 16:39:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	verify_map(t_map *map)
{
	int	index;

	index = map->map_start - 1;
	if (!get_types(map))
		exit_error(map, TYPES_ERROR);
	if (!get_spawn(map))
		exit_error(map, SPAWN_ERROR);
	if (!verify_breaks(map))
		exit_error(map, BREAKS_ERROR);
	if (!verify_walls(map))
		exit_error(map, WALL_ERROR);
}
