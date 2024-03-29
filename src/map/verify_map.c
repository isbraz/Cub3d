/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:08:59 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	verify_map(t_map *map)
{
	if (!get_types(map))
		exit_parsing_error(map, TYPES_ERROR);
	if (!get_spawn(map))
		exit_parsing_error(map, SPAWN_ERROR);
	if (!verify_breaks(map))
		exit_parsing_error(map, BREAKS_ERROR);
	if (!verify_walls(map))
		exit_parsing_error(map, WALL_ERROR);
}
