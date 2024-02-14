/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:08:59 by user              #+#    #+#             */
/*   Updated: 2024/02/14 19:16:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	verify_map(t_map *map)
{
	if (!get_types(map))
		exit_error(map, TYPES_ERROR);
	if (!get_spawn(map))
		exit_error(map, SPAWN_ERROR);
	if (!verify_breaks(map))
		exit_error(map, BREAKS_ERROR);
	if (!verify_walls(map))
		exit_error(map, WALL_ERROR);
}
